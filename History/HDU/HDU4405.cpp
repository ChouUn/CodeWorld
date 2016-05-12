/*
 *    Name : HDU4405.cpp
 *    Author : CHN.ChouUn
 *    Date : 2015��3��18�� ����7:48:40
 *    Copyright : www.fateud.com
 *    Email : ChouUnSoft@gmail.com
 *    Description : None
 */

#include <standard.h>

#define maxN 1000010

double f[maxN];
int g[maxN];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) && (n || m)) {
        CLEAR(g, 0xff);
        while (m--) { int x, y; scanf("%d%d", &x, &y); g[x] = y; }

        CLEAR(f, 0x00);
        per (i, n) {
            if (g[i] > -1)
                f[i] = f[g[i]];
            else {
                FOR (k, 1, 6) f[i] += f[i + k];
                f[i] = f[i] / 6 + 1.;
            }
        }
        printf("%.4lf\n", f[0]);
    }
    return 0;
}
