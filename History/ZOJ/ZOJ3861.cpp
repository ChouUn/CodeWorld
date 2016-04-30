/*
 *	Name : ZOJ3861.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月14日 下午5:30:56
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 11
int num[maxN];
bool vis[maxN];

bool check(int x, int y) {
	if (x > y) return check(y, x);
	if (x + y == 10) return vis[5];
	if (x == 1 && y == 3) return vis[2];
	if (x == 1 && y == 7) return vis[4];
	if (x == 3 && y == 9) return vis[6];
	if (x == 7 && y == 9) return vis[8];
	return true;
}

int arr2dec(int x, int y) { return (x << 3) + (x << 1) + y; }

//@ Main Function
int main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> num[i];

		set<int> ans;
		sort(num, num + n);
		do {
			bool flag = true;
			memset(vis, 0x00, sizeof(vis));
			for (int i = 0; i < n; i++) {
				if (i && !check(num[i-1], num[i])) { flag = false; break; }
				vis[num[i]] = true;
			}
			if (flag) ans.insert(accumulate(num, num + n, 0, arr2dec));
		} while (next_permutation(num, num + n));

		printf("%u\n", ans.size());
		for (set<int>::iterator i = ans.begin(); i != ans.end(); i++)
			for (int j = (*i), k = round(pow(10.0, n - 1)); j; k /= 10) {
				putchar(j / k + '0');
				putchar((j %= k) ? ' ' : '\n');
			}
	}
	return 0;
}
