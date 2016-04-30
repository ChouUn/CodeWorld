/*
 *	Name : ZOJ3869.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月25日 下午10:37:23
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 1010
int cnt[maxN], pnt[maxN];

bool cmp(const int &a, const int &b) {
  return cnt[a] > cnt[b];
}

//@ Main Function
int main() {
	int _; scanf("%d", &_);
	while (_--) {
	  memset(cnt, 0x00, sizeof(cnt));
	  int n; scanf("%d", &n);
	  while (n--) {
	    int x; scanf("%d", &x);
	    cnt[x]++;
	  }
	  for (int i = 0; i < maxN; i++) pnt[i] = i;
	  sort(pnt, pnt + maxN, cmp);
	  if (cnt[pnt[0]] == cnt[pnt[1]])
	    printf("Nobody\n");
	  else
	    printf("%d\n", pnt[0]);
	}
	return 0;
}
