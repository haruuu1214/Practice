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
    
    int n, k;
    cin >> n >> k;

    --k;

    int x = 0, y = n / 2;

    int p = k / n;
    int q = k % n;

    x += 2 * p;
    y -= p;
    x %= n;
    x = (x + n) % n;
    y %= n;
    y = (y + n) % n;

    x -= q;
    y += q;
    x %= n;
    x = (x + n) % n;
    y %= n;
    y = (y + n) % n;

    cout << x + 1 << " " << y + 1 << "\n";
    
    return 0;
}
/*
3 5
-> 2 2

5 24
-> 1 2

5 20
-> 3 4
*/