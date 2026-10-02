#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct BIT
{
    int N;
    vector <int> info;
    BIT(int n) : N(n), info(n + 1) {}
    void update(int idx, int val) {
        for (int i = idx; i <= N; i += i & -i)
            info[i] += val;
    }
    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i)
            res += info[i];
        return res;
    }
};

int a[200005];

signed main()
{
    IOS
    
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    
    BIT bit(n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int now;
        now = (bit.query(a[i] - 1) + 1) % mod;
        bit.update(a[i], now);
        cnt = (cnt + now) % mod;
    }
    cout << cnt << "\n";
    
    return 0;
}