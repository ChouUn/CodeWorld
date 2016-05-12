/*
 *	Name : ZOJ3875.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月25日 下午10:54:02
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

struct node {
  int d;
  string s;
}a[110];

bool cmp(const node &a, const node &b) {
  return a.d > b.d;
}

string str;
int ans;
void solve(int n) {
  for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].d;
  sort(a, a + n, cmp);
  ans += a[(n-1)/2].d;
  str += a[(n-1)/2].s;
}

//@ Main Function
int main() {
  int _; cin >> _;
  while (_--) {
    int n, m, p; cin >> n >> m >> p;
    ans = 0; str = "";
    solve(n); str += " ";
    solve(m); str += " ";
    solve(p); str += "\n";
    cout << ans << " " << str;
  }
  return 0;
}
