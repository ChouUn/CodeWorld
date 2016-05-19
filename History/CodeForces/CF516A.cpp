/*
 *	Name : CF516A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月18日 上午12:13:21
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	// Init
	int n; cin >> n;
	string str; cin >> str;

	// Solve
	string ans;
	REP(i,n) {
		switch (str[i]) {
			case '9':
				ans += "7332";
				break;
			case '8':
				ans += "7222";
				break;
			case '6':
				ans += "53";
				break;
			case '4':
				ans += "322";
				break;
			case '7': case '5': case '3': case '2':
				ans += str[i];
				break;
			default :
				break;
		}
	}

	// Output
	sort(all(ans), greater<char>());
	cout << ans << endl;
	return 0;
}
