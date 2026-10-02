#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define X first 
#define Y second
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e13;


const int N = 105;

pii _minus(pii p, pii q) {
    return {p.X - q.X, p.Y - q.Y};
}

int dot(pii p, pii q) {
    return p.X * q.X + p.Y * q.Y;
}

pii route[N];

signed main() {
    IO;
    
    pii p;
    int n;
    cin >> p.X >> p.Y >> n;
    for (int i = 1; i <= n + 1; i++)
        cin >> route[i].X >> route[i].Y;
    
    double mn = INF;
    for (int i = 1; i <= n; i++) {
        pii b1 = _minus(route[i + 1], route[i]);
        pii b2 = _minus(p, route[i]);
        int d = dot(b1, b2);
        if (d < 0) continue;
        double tmp = (double)d / sqrt(b1.X * b1.X + b1.Y * b1.Y);
        if (d >= (b1.X * b1.X + b1.Y * b1.Y))
            continue;
        double res = (double)(b2.X * b2.X + b2.Y * b2.Y) - tmp * tmp;
        res = sqrt(res);
        mn = min(mn, res);
    }
    for (int i = 1; i <= n + 1; i++) {
        double res = sqrt((route[i].X - p.X) * (route[i].X - p.X) + (route[i].Y - p.Y) * (route[i].Y - p.Y));
        mn = min(mn, res);
    }
    cout << fixed << setprecision(10) << mn << "\n";
    
    return 0;
}