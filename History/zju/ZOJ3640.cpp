/*
 *	Name : zju3640.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��3��19�� ����3:43:39
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 110
#define maxM 10010
#define calc(x) ((int)(sqr(x) * (1. + sqrt(5.)) * .5))

int v[maxN];
double dp[maxM * 3];

int main() {
    int n, f;
    while (cin >> n >> f) {
    	REP (i, n) cin >> v[i];

    	int m = 0;
    	REP (i, n) exmax(m, v[i]);
    	m = max(m * 2, f);

    	CLEAR(dp, 0x00);
    	FOR (i, m, f) {
    		REP (k, n)
    			dp[i] += (i > v[k]) ? calc(v[k]) : (dp[i + v[k]] + 1);
    		dp[i] /= n;
    	}
    	printf("%.3f\n", dp[f]);
    }

    return 0;
}
