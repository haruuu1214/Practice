#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

const int N = 500005;

signed main()
{
    IOS
    
    int n;
    cin >> n;
    vector <pair<string, pii>> v;
    string s;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> s >> a >> b;
        v.push_back({s, {a, b}});
    }
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (auto i : v) {
        auto [x, y] = i.second;
        if (x < m || (x == m && y <= d))
            ans++;
    }
    cout << ans << "\n";
    
    return 0;
}