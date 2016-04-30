/*
 *	Name : CF518E.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月25日 上午1:53:52
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 100010

int n, k, a[maxN];

int getRange(int l, int r, int m) {
	int t = m / 2;
	t = min(t, r - 1);
	t = max(t, l + m);
	return t;
}

int main() {
	cin >> n >> k;
	REP(i,n) {
		string s; cin >> s;
		if (s == "?")
			a[i] = INT_MAX;
		else
			sscanf(&s[0], "%d", a + i);
	}
	
	REP (s, min(n,k)) {
		int cnt = 0, first = -INT_MAX;
		for (int i = s; i < n + k; i += k) {
			int last = (i < n) ? (a[i]) : (INT_MAX - 1);
			if (last == INT_MAX) { cnt ++; continue; }
			if (first + cnt >= last) {
				cout << "Incorrect sequence" << endl;
				return 0;
			}
			int v = getRange(first, last, cnt);
			for (int x = i; cnt; cnt--)
				a[x -= k] = v --;
			cnt = 0, first = last;
		}
	}

	REP(i,n) cout << a[i] << ' '; cout << endl;
	return 0;
}
