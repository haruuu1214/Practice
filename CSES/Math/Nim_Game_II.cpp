#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[200005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= 4;
    }
    int S = 0;
    for (int i = 1; i <= n; i++)
        S ^= a[i];
    if (S == 0)
        cout << "second\n";
    else
        cout << "first\n";
}

signed main()
{
    IO;
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}