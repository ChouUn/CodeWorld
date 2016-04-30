/*
 *	Name: CF190D.cpp
 *	Author: CHN.ChouUn
 *	Date: 2015年2月9日 下午11:42:48
 *	Copyright: www.fateud.com
 *	Email: ChouUnSoft@gmail.com
 *	Description: None
 */

#include <standard.h>

#define maxN 400010
int a[maxN];

int main() {
    int n, k;
    Int64 ans = 0LL;
    map<int, int> mp;
    scanf("%d%d", &n, &k);
    for (int i = 0, p = 0; i < n; i++) {
        scanf("%d", a + i);
        if (++mp[a[i]] >= k) {
            do {
                ans += n - i;
                --mp[a[p]];
            }while (a[p++] != a[i]);
        }
    }
    printf(FMT "\n", ans);
    return 0;
}
