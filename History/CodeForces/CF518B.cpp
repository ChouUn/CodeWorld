/*
 *	Name : CF518B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月25日 上午12:28:44
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int hs[256], ht[256];

int main() {
	string s, t;
	cin >> s >> t;

	REP(i,s.sz) hs[(size_t)s[i]] ++;
	REP(i,t.sz) ht[(size_t)t[i]] ++;

	int p = 0;
	FOR(i,'A','z') {
		int d = min(hs[i], ht[i]);
		hs[i] -= d, ht[i] -= d, p += d;
	}

	int q = 0;
	FOR(i,'A','Z') {
		hs[i] += hs[i^32], ht[i] += ht[i^32];
		int d = min(hs[i], ht[i]);
		hs[i] -= d, ht[i] -= d, q += d;
	}

	cout << p << ' ' << q << endl;
	return 0;
}
