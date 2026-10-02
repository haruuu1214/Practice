#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll INF = 1e18;

const int N = 50005;
const int MXN = 32000; /// (int)sqrt(1e9) + 1
int a[N];
ll b[N];
vector <int> facs[N];
vector <pll> G[12 * N];
ll dis[12 * N];

vector <int> primes;
bitset <32000> not_prime;


signed main()
{
    IOS
    
    for (int i = 2; i < MXN; i++) {
        if (!not_prime[i])
            primes.push_back(i);
        for (int j : primes) {
            if (i * j >= MXN) break;
            not_prime[i * j] = true;
            if (i % j == 0) break;
        }
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> a[n + 1];

    vector <int> nums;
    for (int i = 1; i <= n + 1; i++) {
        for (int &j : primes) {
            if (a[i] < j) break;
            if (a[i] % j == 0) {
                facs[i].push_back(j);
                while (a[i] % j == 0)
                    a[i] /= j;
            }
        }
        if (a[i] > primes.back())
            facs[i].push_back(a[i]);
        for (int &j : facs[i])
            nums.push_back(j);
    }
    nums.push_back(0);
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i = 1; i <= n + 1; i++) {
        for (int &j : facs[i]) {
            int _fac = lower_bound(nums.begin(), nums.end(), j) - nums.begin();
            int _i = nums.size() + i;
            if (i != n + 1)
                G[_fac].push_back({_i, b[i]});
            G[_i].push_back({_fac, 0});
        }
    }

    fill(dis, dis + (12 * N), INF);
    int S = nums.size() + n + 1;
    dis[S] = 0;
    priority_queue <pll, vector<pll>, greater<pll>> Q;
    Q.push({0, S});
    ll d, v;
    while (!Q.empty()) {
        d = Q.top().first;
        v = Q.top().second;
        Q.pop();
        if (d != dis[v])
            continue;
        for (auto [u, w] : G[v]) {
            if (dis[v] + w < dis[u]) {
                dis[u] = dis[v] + w;
                Q.push({dis[u], u});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ll res = INF;
        for (int &j : facs[i]) {
            int id = lower_bound(nums.begin(), nums.end(), j) - nums.begin();
            res = min(res, dis[id]);
        }
        cout << (res == INF ? -1ll : res) << " ";
    }
    
    return 0;
}