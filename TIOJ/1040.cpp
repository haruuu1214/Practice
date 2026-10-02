#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 100005;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << a << '/' << b << " = ";
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    vector <int> v;
    while (b != 1) {
        int p = a / b;
        int q = a % b;
        v.push_back(p);
        a = q;
        swap(a, b);
    }
    v.push_back(a);

    if (v.size() == 1) {
        cout << v[0] << "\n";
    } else {
        cout << v[0];
        for (int i = 1; i + 1 < v.size(); i++) {
            cout << "+1/{";
            cout << v[i];
        }
        cout << "+1/";
        cout << v.back();
        for (int i = 1; i + 1 < v.size(); i++)
            cout << "}";
        cout << "\n";
    }
}

signed main() {
    IO
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}