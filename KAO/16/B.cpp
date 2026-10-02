#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    int x[3], y[3];
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

    auto check = [&]() {
        int a = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
        int b = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);
        return (a == b);
    };

    if (!check()) {
        swap(x[0], x[1]);
        swap(y[0], y[1]);
        if (!check()) {
            swap(x[0], x[2]);
            swap(y[0], y[2]);
        }
    }

    cout << x[1] + x[2] - x[0] << " " << y[1] + y[2] - y[0] << "\n";
    
    return 0;
}