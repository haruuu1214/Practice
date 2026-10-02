#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

int bit[N];
void update(int id, int val) {
    for (int i = id; i <= 100000; i += i & -i)
        bit[i] += val;
}

int query(int id) {
    int res = 0;
    for (int i = id; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}
pii a[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    vector <int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        v.push_back(a[i].first);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++)
        a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
    
    v.clear();

    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
        a[i].second *= -1;
        v.push_back(a[i].second);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++)
        a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
    
    int ans = 0;
    sort(a + 1, a + n + 1, [](pii p, pii q) {
        if (p.first != q.first)
            return p.first < q.first;
        return p.second > q.second;
    });
    for (int i = 1; i <= n; i++) {
        ans += query(a[i].second - 1);
        update(a[i].second, 1);
    }
    cout << ans << "\n";
 
    return 0;
}