#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;
int a[50], p[50];

signed main() {
    IO;
    
    int n;
    while (cin >> n) {
        if (!n) break;
        int sum = 0;
        set <int> S;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
            for (int j = 0; j < i; j++)
                S.insert(p[i] - p[j]);
            sum += a[i];
        }
        if (S.size() == sum && n != sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}