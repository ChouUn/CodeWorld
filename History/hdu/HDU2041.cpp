/*
 *	Name : HDU2041.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午2:46:20
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 41

Int64 f[maxN] = {0, 1};

int main() {
	FOR(i,2,maxN-1) f[i] = f[i-1] + f[i-2];
	
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}
