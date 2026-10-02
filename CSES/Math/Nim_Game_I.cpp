#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define STL(x) for (auto &HEHE : x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[200005];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
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
    IOS
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}