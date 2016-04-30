#include <stdio.h>
#include <stdlib.h>

#define maxN 1000010

int num[maxN];
int pre[maxN];
int sum[maxN];

int main() {
    pre[0] = 0;
    for(int i = 1; i < maxN; i++) {
        num[i] = (rand() << 16) + rand();
        pre[i] = pre[i - 1]^ num[i];
    }

    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            int data; scanf("%d", &data);
            sum[i + 1] = sum[i] ^ num[data];
        }
        while (m--) {
            int x, y; scanf("%d%d", &x, &y);
            if ((sum[y] ^ sum[x - 1]) != (pre[y - x + 1] ^ pre[0]))
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}
