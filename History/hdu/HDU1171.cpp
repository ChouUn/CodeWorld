/*
 *	Name : HDU1171.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月7日 下午2:43:07
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN (50*100*50 + 10)

bool f[maxN];

int main() {
	int n;
	while (cin >> n && n > 0) {
		CLEAR(f, 0x00);
		f[0] = 1;

		int sum = 0;
		while(n--) {
			int v, m; cin >> v >> m;
			for (int dv, dm = 1; m;) {
				dv = dm * v;
				m = m - dm;
				dm = min(dm * 2, m);

				sum += dv;
				FOR(i, sum, dv) f[i] = f[i] || f[i - dv];
			}
		}

		int min;
		for (min = sum / 2; !f[min]; min--);
		cout << sum - min << " " << min << endl;
	}
	return 0;
}
