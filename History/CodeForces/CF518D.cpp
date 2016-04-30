/*
 *	Name : CF518D.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月25日 上午1:18:46
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 2010

int n, t; double p;
double dp[maxN];

int main() {
	cin >> n >> p >> t;
	double q = 1. - p;

	dp[0] = 1;
	REP(i,t)
		FOR(j,n-1,0)
			dp[j+1]	+=	dp[j] * p,
			dp[j]	=	dp[j] * q;

	double ans = 0;
	FOR(j,0,n) ans += j * dp[j];
	printf("%.9lf\n", ans);
	return 0;
}
