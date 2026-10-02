#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void debug() { cerr << endl; }
template <typename T, typename ...U>
void debug(T i, U ...j) { cerr << i << ' ', debug(j...); }
#define test(...) debug("[" #__VA_ARGS__ "]:", __VA_ARGS__)
 
struct BIT {
    vector<int> bit;
    int n;
    BIT(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void update(int i, int val) {
        for (; i <= n; i += i & -i) bit[i] += val;
    }
    int kth(int k) {
        int i = 0;
        for (int j = 1 << __lg(n); j; j >>= 1) {
            if (i + j <= n && bit[i + j] < k) {
                k -= bit[i + j];
                i += j;
            }
        }
        return i + 1;
    }
};

const int N = 2e5 + 5;
int a[N];
 
signed main() {
	IO;
	int n, q;
    cin >> n;
    q = n;
    BIT bit(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) bit.update(i, 1);
    while (q--) {
        int k;
        cin >> k;
        int id = bit.kth(k);
        cout << a[id] << " ";
        bit.update(id, -1);
    }
}