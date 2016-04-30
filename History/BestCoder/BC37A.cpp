/*
 *	Name : BC37A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月17日 下午6:50:31
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
char s[maxN], t[maxN];

bool cycle(char s[], int n) {
	for (int i = 0, j = n - 1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}

//@ Main Function
int main() {
	for (int n; cin >> n >> s;) {
		for (int i = 0; i <= n; i++)
			t[i] = (s[i] == '?') ? 'a' : s[i];
		cycle(t, n);
	}
	return 0;
}
