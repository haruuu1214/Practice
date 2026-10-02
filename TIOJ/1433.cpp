#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 105;
char a[N][N];
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    int al, ar, bl, br;
    char c;
    fill(&a[0][0], &a[0][0] + N * N, 'o');
    for (int i = 1; i <= n; i++) {
        cin >> bl >> al >> br >> ar;
        cin >> c;
        for (int j = al; j <= ar; j++)
            for (int k = bl; k <= br; k++)
                a[j][k] = c;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
/*
1
4 3 1
1 2 1 2 A
*/
signed main() {
    IO
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}