#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 200005;
int a[N], cnt[N];
int l_used[N];
bool l[N], r[N];
int to[N];
int bit[N];

void update(int id, int val) {
    for (int i = id; i <= 200000; i += i & -i)
        bit[i] += val;
}

int query(int id) {
    int sum = 0;
    for (int i = id; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

signed main() {
    IO;
    
    int n, k;
    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];
    FOR (i, 1, n) cnt[a[i]] += 1;
    int pairs = 0;
    int l_id, mid;
    l_id = 1;
    FOR (i, 1, n) {
        if (cnt[a[i]] == 1)
            ;
        else {
            pairs += 1;
            if (l_used[a[i]] > 0)
                to[i] = l_used[a[i]];
            else {
                to[i] = l_id++;
                l_used[a[i]] = to[i] + k;
            }
        }
    }
    mid = 1 + pairs / 2;
    FOR (i, 1, n)
        if (! to[i])
            to[i] = mid++;

    int ans = 0;
    FOR (i, 1, n) {
        ans += query(200000) - query(to[i]);
        update(to[i], 1);
    }
    cout << ans << "\n";
    
    return 0;
}