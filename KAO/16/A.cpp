#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    auto cmp = [](string a, string b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                return a[i] < b[i];
        return true;
    };

    int n;
    cin >> n;
    string a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        if (cmp(a, b))
            swap(a, b);
        if (cmp(a, c))
            swap(a, c);
        cout << a << "\n";
    }
    
    return 0;
}