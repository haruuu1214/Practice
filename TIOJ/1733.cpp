#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 55;
int a[N][N], pre[N][N];

signed main()
{
    IO
    
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        
        int mx = a[1][1];
        for (int ai = 1; ai <= n; ai++)
            for (int aj = 1; aj <= m; aj++)
                for (int bi = ai; bi <= n; bi++)
                    for (int bj = aj; bj <= m; bj++)
                        mx = max(mx, pre[bi][bj] + pre[ai - 1][aj - 1] - pre[ai - 1][bj] - pre[bi][aj - 1]);
        cout << mx << "\n";
    }
    
    return 0;
}