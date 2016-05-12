/*
 *	Name : zju3603.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��23�� ����4:11:35
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxC 26
#define maxN 20
int cnt[maxC], tmp[maxC];
char str[maxN];

//@ Main Function
int main() {
	int _; scanf("%d", &_);
	while (_--) {
	  int n; scanf("%d", &n);
	  memset(cnt, 0x3f, sizeof(cnt));
	  for (int i = 0; i < n; i++) {
	      scanf("%s", str);
	      memset(tmp, 0x00, sizeof(tmp));
	      for (int j = 0; str[j]; j++) tmp[str[j] - 'A']++;
	      for (int j = 0; j < maxC; j++) cnt[j] = min(cnt[j], tmp[j]);
	  }
	  for (int i = 0; i < maxC; i++)
	    while (cnt[i]--) printf("%c", i + 'A');
	  printf("\n");
	}
	return 0;
}
