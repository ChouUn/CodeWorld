// Name : Graph 图论
// Copyright : fateud.com

#ifndef GRAPH_H_
#define GRAPH_H_ 20150911L

#include <vector>

namespace csl {
  template <typename T>
  struct _graph_node {
    typedef T value_type;
    typedef std::size_t size_type;

    typedef _graph_node< T >* _Link;
    typedef _graph_node< T > _Self;

    _graph_node() :
        prev(), next(), from(), to(), data() {
    }

    _graph_node(_Link a, _Link b, size_type c, size_type d, value_type e) :
        prev(a), next(b), from(c), to(d), data(e) {
    }

    _Link prev;
    _Link next;
    size_type from;
    size_type to;
    value_type data;
  };

  template <typename T>
  struct graph {
    // template parameter.
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;

    typedef _graph_node< T >* iterator;

    typedef _graph_node< T > _Node;
    typedef _graph_node< T >* _Link;
    typedef graph< T > _Self;

    typedef std::size_t size_type;

    explicit graph(size_type V = 0, size_type E = 0) :
        m_size() {
      impl.reserve(V), data.reserve(E);
    }

    inline void build(size_type V, size_type E) {
      impl.assign(V, _Link()), data.resize(E), m_size = 0;
    }

    inline size_type size() const {
      return m_size;
    }

    // element access.
    inline _Link getHead(size_type x) const {
      return impl[x];
    }

    inline _Link getEdge(size_type x) {
      return data.data() + x;
    }

    inline size_type getEdgeIndex(_Link x) const {
      return x - data.data();
    }

    inline void add_edge(size_type from, size_type to, const value_type& data) {
      _add_edge(from, to, data);
    }

    inline void add_double_edge(size_type from, size_type to, const value_type& data) {
      _add_edge(from, to, data), _add_edge(to, from, data);
    }

    inline void add_couple_edge(size_type from, size_type to, const value_type& data1,
                                const value_type& data2 = value_type()) {
      _add_edge(from, to, data1), _add_edge(to, from, data2);
    }

    std::vector< _Link > impl;
    std::vector< _Node > data;
    size_type m_size;

    void _add_edge(size_type from, size_type to, const value_type& value) {
      _Link node = data.data() + m_size++;
      *node = _Node(0, impl[from], from, to, value);
      if (impl[from]) impl[from]->prev = node;
      impl[from] = node;
    }
  };

  template <typename _Tp>
  struct tarjan {
  public:
    typedef typename graph< _Tp >::_Link _Link;

    typedef std::size_t size_type;

  private:
    void __scc(size_type u) {
      dfn[u] = low[u] = ++idx;
      vis[u] = true;
      sta.push_back(u);
      for (_Link i = map->getHead(u); i; i = i->next) {
        size_type v = i->to;
        if (!dfn[v]) {
          __scc(v);
          if (low[u] > low[v]) low[u] = low[v];
        }
        else {
          if (vis[v] && low[u] > dfn[v]) low[u] = dfn[v];
        }
      }
      if (dfn[u] == low[u]) {
        size_type w;
        do {
          w = sta.back();
          sta.pop_back();
          vis[w] = false;
          key[w] = cnt;
        } while (w != u);
        ++cnt;
      }
    }

    void __dcc(size_type u, size_type p) {
      dfn[u] = low[u] = ++idx;
      sta.push_back(u);
      for (_Link i = map->getHead(u); i; i = i->next) {
        size_type v = i->to;
        if (v == p) continue;
        if (!dfn[v]) {
          __dcc(v, u);
          if (low[u] > low[v]) low[u] = low[v];
          if (dfn[u] < low[v]) {
            size_type w;
            do {
              w = sta.back();
              sta.pop_back();
              key[w] = cnt;
            } while (w != v);
            cnt++;
          }
        }
        else {
          if (low[u] > dfn[v]) low[u] = dfn[v];
        }
      }
    }

  public:
    void scc(graph< _Tp >& __map) {
      map = &__map;
      size_type __n = map->impl.size();
      idx = 0;
      cnt = 0;
      sta.reserve(__n);
      dfn.assign(__n, 0);
      low.resize(__n);
      key.resize(__n);
      vis.assign(__n, false);

      for (size_type i = 0; i < __n; ++i)
        if (!dfn[i]) __scc(i);
    }

    void dcc(graph< _Tp >& __map) {
      map = &__map;
      size_type __n = map->impl.size();
      idx = 0;
      cnt = 0;
      sta.reserve(__n);
      dfn.assign(__n, 0);
      low.resize(__n);
      key.resize(__n);

      for (size_type i = 0; i < __n; ++i) {
        if (dfn[i]) continue;
        sta.clear();
        __dcc(i, -1);
        for (size_type j = 0; j < sta.size(); ++j)
          key[sta[j]] = cnt;
        cnt++;
      }
    }

    inline size_type operator[](const size_type __x) const {
      return key[__x];
    }

    inline size_type size() const {
      return cnt;
    }

  private:
    graph< _Tp >* map;
    size_type idx;
    size_type cnt;
    std::vector< size_type > sta;
    std::vector< size_type > dfn;
    std::vector< size_type > low;
    std::vector< size_type > key;
    std::vector< bool > vis;
  };

} // namespace csl

#endif /* GRAPH_H_ */
