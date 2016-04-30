// Name : sb_tree.h 中文名
// Copyright : fateud.com

#ifndef SB_TREE_CPP_
#define SB_TREE_CPP_ 20150810L

//#include <bits/move.h>

namespace csl {
  struct sb_tree_node_base {
    typedef sb_tree_node_base* _Base_ptr;
    typedef const sb_tree_node_base* _Const_Base_ptr;

    _Base_ptr m_parent;
    _Base_ptr m_left;
    _Base_ptr m_right;
    std::size_t m_size;

    sb_tree_node_base() :
        m_parent(), m_left(), m_right(), m_size(1) {
    }

    static inline _Base_ptr s_minimum(_Base_ptr __x) {
      while(__x->m_left)
        __x = __x->m_left;
      return __x;
    }

    static inline _Const_Base_ptr s_minimum(_Const_Base_ptr __x) {
      while(__x->m_left)
        __x = __x->m_left;
      return __x;
    }

    static inline _Base_ptr s_maximum(_Base_ptr __x) {
      while(__x->m_right)
        __x = __x->m_right;
      return __x;
    }

    static inline _Const_Base_ptr s_maximum(_Const_Base_ptr __x) {
      while(__x->m_right)
        __x = __x->m_right;
      return __x;
    }

  };

  template<typename _Tp>
  struct sb_tree_node : public sb_tree_node_base {
    typedef sb_tree_node<_Tp>* _Link_type;

    _Tp m_value;

    sb_tree_node(_Tp __x) :
        m_value(__x) {
    }
  };

  inline void sb_tree_left_rotate(sb_tree_node_base*& __x) {
    sb_tree_node_base* __y = __x->m_right;
    __x->m_right = __y->m_left;
    __y->m_left = __x;
    __y->m_size = __x->m_size;
    __x->m_size = __x->m_left->m_size + __x->m_right->m_size + 1;
    __x = __y;
  }

  inline void sb_tree_right_rotate(sb_tree_node_base*& __x) {
    sb_tree_node_base* __y = __x->m_left;
    __x->m_left = __y->m_right;
    __y->m_right = __x;
    __y->m_size = __x->m_size;
    __x->m_size = __x->m_left->m_size + __x->m_right->m_size + 1;
    __x = __y;
  }

  void sb_tree_maintain(sb_tree_node_base* __x,bool __f) {
    if(__x == 0) return;
    if(__f == true) {
      std::size_t __l = __x->m_left ? __x->m_left->m_size : 0;
      std::size_t __rl =
          __x->m_right ?
              __x->m_right->m_left ? __x->m_right->m_left->m_size : 0 : 0;
      std::size_t __rr =
          __x->m_right ?
              __x->m_right->m_right ? __x->m_right->m_right->m_size : 0 : 0;
      if(__rr > __l) sb_tree_left_rotate(__x);
      else if(__rl > __l) sb_tree_right_rotate(__x->m_right), sb_tree_left_rotate(
          __x);
      else return;
    }
    else {
      std::size_t __r = __x->m_right ? __x->m_right->m_size : 0;
      std::size_t __ll =
          __x->m_left ?
              __x->m_left->m_left ? __x->m_left->m_left->m_size : 0 : 0;
      std::size_t __lr =
          __x->m_left ?
              __x->m_left->m_right ? __x->m_left->m_right->m_size : 0 : 0;
      if(__ll > __r) sb_tree_right_rotate(__x);
      else if(__lr > __r) sb_tree_left_rotate(__x->m_left), sb_tree_right_rotate(
          __x);
      else return;
    }
    sb_tree_maintain(__x->m_left, false);
    sb_tree_maintain(__x->m_right, true);
    sb_tree_maintain(__x, true);
    sb_tree_maintain(__x, false);
  }

  sb_tree_node_base*
  sb_tree_increment(sb_tree_node_base* __x) {
    if(__x->m_right) __x = sb_tree_node_base::s_minimum(__x->m_right);
    else {
      sb_tree_node_base* __y = __x->m_parent;
      for(; __x == __y->m_right; __x = __y, __y = __y->m_parent)
        ;
      if(__x->m_right != __y) __x = __y;
    }
    return __x;
  }

  sb_tree_node_base*
  sb_tree_decrement(sb_tree_node_base* __x) {
    if(__x->m_parent->m_parent == __x) __x = __x->m_right;
    else if(__x->m_left) __x = sb_tree_node_base::s_maximum(__x->m_left);
    else {
      sb_tree_node_base* __y = __x->m_parent;
      for(; __x == __y->m_left; __x = __y, __y = __y->m_parent)
        ;
      __x = __y;
    }
    return __x;
  }

  template<typename _Tp>
  class sb_tree_iterator {
  public:
    typedef _Tp value_type;
    typedef _Tp& reference;
    typedef _Tp* pointer;

    typedef sb_tree_iterator<_Tp> _Self;
    typedef sb_tree_node_base::_Base_ptr _Base_ptr;
    typedef sb_tree_node<_Tp>* _Link_type;

    sb_tree_iterator() :
        m_node() {
    }

    explicit sb_tree_iterator(_Link_type __x) :
        m_node(__x) {
    }

    reference operator *() const {
      return static_cast<_Link_type>(m_node)->m_value;
    }

    pointer operator ->() const {
      return std::__addressof(static_cast<_Link_type>(m_node)->m_value);
    }

    _Self&
    operator ++() {
      m_node = sb_tree_increment(m_node);
      return *this;
    }

    _Self operator ++(int) {
      _Self __tmp = *this;
      m_node = sb_tree_increment(m_node);
      return __tmp;
    }

    _Self&
    operator --() {
      m_node = sb_tree_decrement(m_node);
      return *this;
    }

    _Self operator --(int) {
      _Self __tmp = *this;
      m_node = sb_tree_decrement(m_node);
      return __tmp;
    }

    bool operator ==(const _Self& __x) const {
      return m_node == __x.m_node;
    }

    bool operator !=(const _Self& __x) const {
      return m_node != __x.m_node;
    }

  private:
    _Base_ptr m_node;

  };

  template<typename _Tp>
  class sb_tree {
  public:
    // template parameter.
    typedef _Tp value_type;
    typedef sb_tree_node_base::_Base_ptr _Base_ptr;
    typedef sb_tree_node<_Tp> _Node;
    typedef sb_tree_node<_Tp>* _Link_type;
    typedef sb_tree_iterator<_Tp> iterator;

  private:
    // member variable.
    sb_tree_node_base m_impl;

  private:
    // member function.
    void s_insert(_Base_ptr& __x,_Base_ptr __y,const value_type& __v) {
      if(__x == 0) {
        __x = new _Node(__v);
        __x->m_parent = __y;
        if(m_impl.m_left->m_left) m_impl.m_left = m_impl.m_left->m_left;
        if(m_impl.m_right->m_right) m_impl.m_right = m_impl.m_right->m_right;
      }
      else {
        __x->m_size += 1;
        if(__v < static_cast<_Link_type>(__x)->m_value) s_insert(__x->m_left,
            __x, __v), sb_tree_maintain(__x, false);
        else s_insert(__x->m_right, __x, __v), sb_tree_maintain(__x, true);
      }
    }

    void s_success_erase(_Base_ptr __x) {
      _Link_type __y = static_cast<_Link_type>(__x);
      if(__x->m_parent != &m_impl) while(__x->m_parent->m_parent != __x) {
        __x = __x->m_parent;
        __x->m_size -= 1;
      }
      delete __y;
    }

    void s_erase(_Base_ptr& __x,const value_type& __v) {
      while(__x) {
        const value_type& __k = static_cast<_Link_type>(__x)->m_value;
        if(__v == __k) {
          _Base_ptr __y;
          if(__x->m_right) {
            __y = sb_tree_node_base::s_minimum(__x->m_right);
            if(__y != __x->m_right) __y->m_parent->m_left = __y->m_right;
            else __y->m_parent->m_right = __y->m_right;
            std::swap(static_cast<_Link_type>(__x)->m_value,
                static_cast<_Link_type>(__y)->m_value);
          }
          else if(__x->m_left) {
            __y = sb_tree_node_base::s_maximum(__x->m_left);
            if(__y != __x->m_left) __y->m_parent->m_right = __y->m_left;
            else __y->m_parent->m_left = __y->m_left;
            std::swap(static_cast<_Link_type>(__x)->m_value,
                static_cast<_Link_type>(__y)->m_value);
          }
          else {
            __y = __x;
            __x = 0;
          }
          _Base_ptr __z = __y->m_parent;
          s_success_erase(__y);
          if(m_impl.m_left == __y) m_impl.m_left = __z;
          if(m_impl.m_right == __y) m_impl.m_right = __z;
          break;;
        }
        else __x = __v < __k ? __x->m_left : __x->m_right;
      }
    }

    void s_init() {
      m_impl.m_parent = 0;
      m_impl.m_left = &m_impl;
      m_impl.m_right = &m_impl;
      m_impl.m_size = 0;
    }

  public:
    // constructor & destructor.
    sb_tree() :
        m_impl() {
      s_init();
    }

    ~sb_tree() {
      clear();
    }

  public:
    // iterators.
    iterator begin() {
      return iterator(m_impl.m_left);
    }

    iterator end() {
      return iterator(static_cast<_Link_type>(&m_impl));
    }

    iterator find(const value_type& __v) {
      _Base_ptr __x = m_impl.m_parent;
      while(__x) {
        value_type& __k = static_cast<_Link_type>(__x)->m_value;
        if(__v == __k) return iterator(static_cast<_Link_type>(__x));
        __x = __v < __k ? __x->m_left : __x->m_right;
      }
      return this->end();
    }

  public:
    // capacity.
    void clear() {
      _Base_ptr __x = m_impl.m_parent;
      if(__x == 0) return;
      __x->m_parent = 0;
      s_init();
      while(__x) {
        _Base_ptr __y = __x;
        if(__x->m_left) {
          __x = __x->m_left;
          __y->m_left = 0;
        }
        else if(__x->m_right) {
          __x = __x->m_right;
          __y->m_right = 0;
        }
        else {
          __x = __x->m_parent;
          delete static_cast<_Link_type>(__y);
        }
      }
    }

    std::size_t size() const {
      return m_impl.m_size;
    }

    bool empty() const {
      return m_impl.m_size == 0;
    }

  public:
    // element access.

  public:
    // modifiers.
    void insert(const value_type& __v) {
      m_impl.m_size += 1;
      s_insert(m_impl.m_parent, &m_impl, __v);
    }

    void erase(const value_type& __v) {
      m_impl.m_size -= 1;
      s_erase(m_impl.m_parent, __v);
    }

  public:
    // operator overloading.
  public:
    // specialized algorithms.
    value_type select(std::size_t __k) const {
      _Base_ptr __x = m_impl.m_parent;
      while(__k) {
        std::size_t __l = __x->m_left ? __x->m_left->m_size : 0;
        if(__k <= __l) __x = __x->m_left;
        else if(__k -= __l + 1) __x = __x->m_right;
      }
      return static_cast<_Link_type>(__x)->m_value;
    }

    std::size_t rank(const value_type& __v) const {
      std::size_t __res = 0;
      for(_Base_ptr __x = m_impl.m_parent; __x;) {
        value_type& __k = static_cast<_Link_type>(__x)->m_value;
        std::size_t __l = __x->m_left ? __x->m_left->m_size : 0;
        if(__v < __k) __x = __x->m_left;
        else __x = __x->m_right, __res += __l + 1;
        if(__v == __k) break;
      }
      return __res;
    }

  };
} // namespace csl

#endif /* SB_TREE_CPP_ */
