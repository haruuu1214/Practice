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
    
    int x, y;
    cin >> x >> y;
    cout << ((x - 1) ^ (y - 1)) << "\n";
    
    return 0;
}