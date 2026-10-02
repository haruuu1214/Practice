#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 1000005;

int a[N];

signed main()
{
    IO
    
    int n;
    cin >> n;
    int l, r;
    int MXN = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        a[l]++;
        a[r]--;
        MXN = max(MXN, r);
    }
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= MXN; i++) {
        sum += a[i];
        ans += sum * (sum - 1) / 2;
    }
    cout << ans << "\n";
    
    return 0;
}