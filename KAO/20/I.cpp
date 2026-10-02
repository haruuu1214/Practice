#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int n, m;
int a[N], b[N];
vector<pair<double, int>> v;

bool check_a(double k) {
    v.resize(n);
    for (int i = 0; i < n; i++)
        v[i] = {(double)a[i] - (double)(a[i] + b[i]) * k, i};
    sort(v.begin(), v.end(), greater<pair<double, int>>());
    double sum = 0;
    for (int i = 0; i < m; i++)
        sum += v[i].first;
    return (sum >= 0);
}

signed main() {
    IO;
    
    cin >> n >> m;
    FOR(i, 0, n - 1) cin >> a[i] >> b[i];
    {
        double l = 0, r = 1;
        while (fabs(l - r) > 1e-5) {
            double mid = (l + r) / 2.0;
            if (check_a(mid))
                l = mid;
            else
                r = mid;
        }
        int U = 0, D = 0;
        for (int i = 0; i < m; i++) {
            U += a[v[i].second];
            D += a[v[i].second] + b[v[i].second];
        }
        int g = __gcd(U, D);
        U /= g;
        D /= g;
        if (D == 0)
            cout << 0 << "\n";
        else if (U % D == 0)
            cout << U / D << "\n";
        else
            cout << U << "/" << D << "\n";
    }
    swap(a, b);
    {
        double l = 0, r = 1;
        while (fabs(l - r) > 1e-5) {
            double mid = (l + r) / 2.0;
            if (check_a(mid))
                l = mid;
            else
                r = mid;
        }
        int U = 0, D = 0;
        for (int i = 0; i < m; i++) {
            U += a[v[i].second];
            D += a[v[i].second] + b[v[i].second];
        }
        int g = __gcd(U, D);
        U /= g;
        D /= g;
        if (D == 0)
            cout << 0 << "\n";
        else if (U % D == 0)
            cout << U / D << "\n";
        else
            cout << U << "/" << D << "\n";
    }

    
    return 0;
}