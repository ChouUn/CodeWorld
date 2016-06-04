// Name : Fast Input/Output 快速读入
// Copyright : fateud.com

#ifndef FASTIO_H_
#define FASTIO_H_ 20160411L

#include <cstdio>
#include <cctype>

namespace csl {
  class fastio {
  public:
    char *head, *tail;
    fastio(char* data, unsigned size) {
      head = data, tail = data + fread(data, sizeof(char), size, stdin);
    }
    inline bool empty() {
      for (char* __x = head; __x < tail; ++__x) {
        if (isspace(*__x)) continue;
        if (isalnum(*__x)) return false;
      }
      return true;
    }
    friend fastio& operator >>(fastio& in, int& x) {
      return in.nextSigned(x), in;
    }
    friend fastio& operator >>(fastio& in, long long& x) {
      return in.nextSigned(x), in;
    }
    friend fastio& operator >>(fastio& in, unsigned int& x) {
      return in.nextUnsigned(x), in;
    }
    friend fastio& operator >>(fastio& in, unsigned long long& x) {
      return in.nextUnsigned(x), in;
    }
    friend fastio& operator >>(fastio& in, char& ch) {
      return ch = *in.head, ++in.head, in;
    }
    friend fastio& operator >>(fastio& in, char* s) {
      for (; in.head < in.tail && isgraph(*s = *in.head); ++s, ++in.head)
        ;
      return *s = 0, in;
    }
    void getline(char* s) {
      for (; head < tail && isprint(*s = *head); ++s, ++head)
        ;
      *s = 0;
    }
  private:
    template <typename _Tp>
    inline void nextSigned(_Tp& x) {
      x = _Tp();
      for (bool __vf = 0; true; ++head)
        if (isdigit(*head))
          x = (x << 3) + (x << 1) + *head - '0', __vf = 1;
        else if (__vf) break;
    }
    template <typename _Tp>
    inline void nextUnsigned(_Tp& x) {
      x = _Tp();
      for (bool __vf = 0, __sf = 0; true; ++head)
        if (isdigit(*head))
          x = (x << 3) + (x << 1) + *head - '0', __vf = 1;
        else if (__vf) {
          if (__sf) x = -x;
          break;
        }
        else if (*head == '-') __sf = true;
    }
  };
} // namespace csl

#endif /* FASTIO_H_ */
