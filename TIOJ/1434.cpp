#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

void solve() {
    int n;
    cin >> n;
    vector <pii> v;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](pii p, pii q) {
        return p.second < q.second;
    });
    int nowt = 0;
    for (auto [t, endt] : v) {
        if (t + nowt > endt) {
            cout << "unschedulable\n";
            return;
        } else {
            nowt += t;
        }
    }
    cout << "schedulable\n";
}

signed main() {
    IO
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}