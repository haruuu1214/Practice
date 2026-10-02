#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 300005;

int bit[N];
void update(int id, int val) {
    for (int i = id; i <= 300000; i += i & -i)
        bit[i] = max(bit[i], val);
}

int query(int id) {
    int res = 0;
    for (int i = id; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}

struct item {
    int A, B, E;
};

signed main() {
    IO;
    
    int n, m, k;
    cin >> n >> m >> k;
    vector <item> v(k);

    for (int i = 0; i < k; i++)
        cin >> v[i].A >> v[i].B >> v[i].E;
    sort(v.begin(), v.end(), [&](item p, item q) {
        if (p.A == q.A)
            return p.B > q.B;
        return p.A < q.A;
    });

    int ans = 0;
    for (auto i : v) {
        int res = query(i.B - 1) + i.E;
        ans = max(ans, res);
        update(i.B, res);
    }
    cout << ans << "\n";
    
    return 0;
}