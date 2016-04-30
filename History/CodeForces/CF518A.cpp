/*
 *	Name : CF518A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月25日 上午12:28:44
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	string s, t;
	cin >> s >> t;

	for (int i = s.sz - 1; i > -1; i--) {
		if (s[i]++ != 'z') break;
		s[i] -= 26;
	}

	cout << (s < t ? s : "No such string") << endl;

	return 0;
}
