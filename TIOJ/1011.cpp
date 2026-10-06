#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;



signed main()
{
    IO;
    
    int n, m;
    cin >> n >> m;
    
    vector <int> v1, v2;
    while (n > 0) {
        v1.push_back(n & 1);
        n >>= 1;
    }

    while (m > 0) {
        v2.push_back(m & 1);
        m >>= 1;
    }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    int presame = 0;
    int sz1 = v1.size();
    int sz2 = v2.size();
    for (int i = 0; i < min(sz1, sz2); i++) {
        if (v1[i] != v2[i]) break;
        presame++;
    }

    cout << (sz1 - presame) + (sz2 - presame) << "\n";

    return 0;
}