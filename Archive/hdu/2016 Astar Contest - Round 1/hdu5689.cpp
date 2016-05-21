//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5689.cpp
 *  Date : 2016年5月22日 上午12:36:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
const int M = 30;
struct node {
  int l[M], r[M];
  bool flag;
};
node a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    string s; getline(cin, s);
    map<string, int> dic;

    rep(i, 0, n) {
      rep(k, 0, M) a[i].l[k] = -10001, a[i].r[k] = 10001;
      getline(cin, s);
      stringstream ss(s);
      do {
        string e, b; int c; ss >> e >> b >> c;
        if (!dic.count(e)) {
          int t = dic.size();
          dic[e] = t;
        }
        int d = dic[e];
        if (b == "==") a[i].l[d] = max(a[i].l[d], c), a[i].r[d] = min(a[i].r[d], c);
        else if (b == ">=") a[i].l[d] = max(a[i].l[d], c);
        else if (b == "<=") a[i].r[d] = min(a[i].r[d], c);
        else if (b == ">") a[i].l[d] = max(a[i].l[d], c + 1);
        else if (b == "<") a[i].r[d] = min(a[i].r[d], c - 1);
        else assert(false);
      } while (ss >> s);
      a[i].flag = true;
      rep(k, 0, M) a[i].flag &= a[i].l[k] <= a[i].r[k];
    }

    rep(i, 0, n) {
      bool blank = false;
      rep(j, 0, i) {
        bool flag = a[i].flag & a[j].flag;
        rep(k, 0, M) if (max(a[i].l[k], a[j].l[k]) > min(a[i].r[k], a[j].r[k])) flag = false;
        if (flag) {
          if (blank) cout << ' '; blank = true;
          cout << j + 1;
        }
      }
      cout << (blank ? "\n" : "unique\n");
    }
  }
  return 0;
}
