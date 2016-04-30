//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5250.cpp
 *  Date : 2015年9月25日 上午12:32:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 48

const int g[6][maxn] = {
  {5,3,0,6,1,7,4,2,8,9,42,11,44,13,14,47,16,17,18,19,20,21,22,23,39,25,
      26,36,28,34,30,31,32,33,10,35,12,37,38,15,40,41,29,43,27,45,46,24,},
  {37,1,2,38,4,39,6,7,13,11,8,14,9,15,12,10,16,17,40,19,41,21,22,42,24,
      25,26,27,28,29,30,31,32,33,34,35,36,23,20,18,5,3,0,43,44,45,46,47,},
  {24,25,26,3,4,5,6,7,0,1,2,11,12,13,14,15,8,9,10,19,20,21,22,23,16,17,
      18,27,28,29,30,31,37,35,32,38,33,39,36,34,40,41,42,43,44,45,46,47,},
  {0,1,2,3,4,5,6,7,32,9,10,35,12,37,14,15,21,19,16,22,17,23,20,18,24,25,
      45,27,43,29,30,40,31,33,34,28,36,26,38,39,8,41,42,11,44,13,46,47,},
  {0,1,47,3,46,5,6,45,8,9,10,11,12,13,14,15,34,17,18,33,20,32,22,23,29,
      27,24,30,25,31,28,26,2,4,7,35,36,37,38,39,40,41,42,43,44,16,19,21,},
  {0,1,2,3,4,13,14,15,8,9,10,11,12,21,22,23,16,17,18,19,20,29,30,31,24,
      25,26,27,28,5,6,7,32,33,34,35,36,37,38,39,45,43,40,46,41,47,44,42,},
};

char c[110];
int s[maxn], t[maxn], v[maxn];
int *p = s, *q = t;

void trans(const int func[]) {
  rep(i, 0, maxn) q[i] = p[func[i]];
  swap(p, q);
}

int dfs(int i, int x) {
  v[i] = 1;
  if(p[i] == x) return 1;
  return dfs(p[i], x) + 1;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";

    rep(i, 0, maxn) p[i] = i;
    cin >> c;
    for(char* ch = c; *ch; ++ch) {
      int type, time = 1;
      switch(*ch) {
        case 'U': type = 0; break;
        case 'R': type = 1; break;
        case 'F': type = 2; break;
        case 'D': type = 3; break;
        case 'L': type = 4; break;
        case 'B': type = 5; break;
      }
      switch(*(ch + 1)) {
        case '\'': time += 2; ++ch; break;
        case '2': time += 1; ++ch; break;
      }
      while(time--) trans(g[type]);
    }

    int ans = 1;
    rep(i, 0, maxn) v[i] = 0;
    rep(i, 0, maxn) if(!v[i]) {
      int x = dfs(i, i);
      if(x == 1) continue;
      ans = ans / __gcd(ans, x) * x;
    }
    cout << ans << '\n';
  }
  return 0;
}
