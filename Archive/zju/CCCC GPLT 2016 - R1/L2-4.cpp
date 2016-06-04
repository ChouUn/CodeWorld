//@ Including Header
#include <csl_std.h>
#include <bits/stl_heap.h>

/**
 *  Name : L2-4.cpp
 *  Date : 2016年6月4日 下午2:28:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

/*
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
“x is the root”：x是根结点；
“x and y are siblings”：x和y是兄弟结点；
“x is the parent of y”：x是y的父结点；
“x is a child of y”：x是y的一个子结点。
 */

const int N = 1010;
int a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m; cin >> n >> m;
//  rep(i, 1, n + 1) cin >> a[i];
//  make_heap(a + 1, a + n + 1, greater<int>());
  rep(i, 1, n + 1) {
    cin >> a[i];
    push_heap(a + 1, a + i + 1, greater<int>());
  }

  string in; getline(cin, in);
  rep(i, 0, m) {
    getline(cin, in);
    stringstream ss(in);
    int x; ss >> x >> in;
    if (in == "and") {
      int y; ss >> y;
      x = find(a + 1, a + n + 1, x) - a;
      y = find(a + 1, a + n + 1, y) - a;
      cout << ((x ^ y) == 1 ? 'T' : 'F') << endl;
    }
    else if (in == "is"){
      ss >> in;
      if (in == "a") {
        int y; ss >> in >> in >> y;
        x = find(a + 1, a + n + 1, x) - a;
        y = find(a + 1, a + n + 1, y) - a;
        cout << (x / 2 == y ? 'T' : 'F') << endl;
      }
      else if (in == "the"){
        ss >> in;
        if (in == "root") cout << (a[1] == x ? 'T' : 'F') << endl;
        else if (in == "parent") {
          int y; ss >> in >> y;
          x = find(a + 1, a + n + 1, x) - a;
          y = find(a + 1, a + n + 1, y) - a;
          cout << (y / 2 == x ? 'T' : 'F') << endl;
        }
        else while(true);
      }
      else while(true);
    }
    else while(true);
  }
  return 0;
}
