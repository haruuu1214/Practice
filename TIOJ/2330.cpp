#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 9e18;


const int N = 100005;
pii a[N], b[1005];
int cst[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second >> cst[i];
    vector<pair<pii, int>> v;
    for (int i = 1; i <= m; i++)
        cin >> b[i].first >> b[i].second;
    
    for (int i = 1; i <= n; i++) {
        int dis = INF;
        for (int j = 1; j <= m; j++) {
            int x = a[i].first - b[j].first;
            int y = a[i].second - b[j].second;
            dis = min(dis, (x * x) + (y * y));
        }
        v.push_back({{dis, cst[i]}, i});
    }
    sort(v.begin(), v.end());
    for (auto p : v)
        cout << p.second << "\n";
    
    return 0;
}