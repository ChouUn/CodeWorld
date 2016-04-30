/*
 *	Name : HDU2043.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午2:53:33
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int T; cin >> T;
	while (T --) {
		string s; cin >> s;

		bool ans = s.sz > 7 && s.sz < 17;

		map<int,bool> g;
		REP(i, s.sz) {
			int c = s[i];
			if (c >= 'a' && c <= 'z')
				g[0] = true;
			else if (c >= 'A' && c <= 'Z')
				g[1] = true;
			else if (c >= '0' && c <= '9')
				g[2] = true;
			else
				g[3] = true;
		}

		int sum = 0;
		TRV(i, g) sum += i->Y;
		ans = ans && (sum > 2);

		puts(ans ? "YES" : "NO");
	}
	return 0;
}
