/*
 *    Name : HDU4405.cpp
 *    Author : CHN.ChouUn
 *    Date : 2015年3月18日 下午7:48:40
 *    Copyright : www.fateud.com
 *    Email : ChouUnSoft@gmail.com
 *    Description : None
 */

/*
 *	Name : standard.h 纸农の标准库
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 1000010

double f[maxN];
double h[maxN];
int g[maxN];

void add(int n, double a, double b) {
	f[n] = (f[n] * h[n] + a * b) / (h[n] + b);
	h[n] = h[n] + b;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) && (n || m)) {
        CLEAR(g, 0xff);
        while (m--) { int x, y; scanf("%d%d", &x, &y); g[x] = y; }

        CLEAR(f, 0x00); f[0] = 0.;
        CLEAR(h, 0x00); h[0] = 1.;
        FOR (i, 0, n - 1) {
        	if (g[i] > -1) {
        		add(g[i], f[i], h[i]);
        	}
        	else {
        		FOR (k, 1, 6)
        			add(i + k, f[i] + 1, h[i] / 6);
        	}
        }
        FOR (i, n + 1, n + 5)
        	add(n, f[i], h[i]);
        printf("%.4lf\n", f[n]);
    }
    return 0;
}
