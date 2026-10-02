#pragma GCC optimize("Ofast, unroll-loops, O3")
#include <cstdio>
#include <cmath>
const int N = 105;
int a[N], b[N];


signed main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int t;
    t = 0;
    while (t <= 10000000) {
        t += 1;
        for (int i = 1; i <= n; i++)
            a[i] = rand() % 4 + 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i] * a[i];
        int sq = sqrtl(sum);
        if (sq * sq == sum)
            break;
    }
    t = 0;
    while (t <= 10000000) {
        t += 1;
        for (int i = 1; i <= m; i++)
            b[i] = rand() % 4 + 1;
        int sum = 0;
        for (int i = 1; i <= m; i++)
            sum += b[i] * b[i];
        int sq = sqrtl(sum);
        if (sq * sq == sum)
            break;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", a[i] * b[j]);
        printf("\n");
    }

    return 0;
}
