/*
 *	Name: CF84D.cpp
 *	Author: CHN.ChouUn
 *	Date: 2015年2月9日 下午11:17:26
 *	Copyright: www.fateud.com
 *	Email: ChouUnSoft@gmail.com
 *	Description: None
 */

#include <standard.h>

#define maxN 100010
struct node{
	int d, index, f;
};

int n; Int64 k;
node e[maxN];

int cmpData(const node &a, const node &b) {
	if (a.d == b.d)
		return a.index < b.index;
	else
		return a.d < b.d;
}

int cmpIndex(const node &a, const node &b) {
	return a.index < b.index;
}
void print(int x, int h) {
	//printf("k = %d, x = %d, h = %d\n", k, x, h);
	int flag = 0;
	sort(e + x, e + n, cmpIndex);
	for (int i = x; i < n; i++) {
		if (!k){
			if (e[i].d <= h) continue;
			if (e[i].f) return;
			e[i].f = 1;
			if (flag)
				printf(" ");
			else
				flag = 1;
			printf("%d", e[i].index);
		}
		if (k) k--;
		if (i == n - 1) i = x - 1, h++;
	}
}

int main() {
	scanf("%d" FMT, &n, &k);
	REP(i,n) {
		scanf("%d", &e[i].d);
		e[i].index = i + 1;
		e[i].f = 0;
	}
	
	sort(e, e + n, cmpData);
	int q = 0, h = 0;
	while(true){
		Int64 tmp = ((Int64)n - q) * (e[q].d - h);
		if (tmp <= k) {
			k -= tmp;
			h = e[q].d;
		}
		else{
			tmp = k / ((Int64)n - q);
			h += tmp;
			k -= tmp * ((Int64)n - q);
			print(q, h);
			break;
		}
		do{
			q++;
		}while (e[q].d == e[q-1].d && q < n);
		if (q == n) break;
	}
	if (k)
		printf("-1");
	printf("\n");
	return 0;
}
