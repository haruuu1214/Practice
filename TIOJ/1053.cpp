#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO
    
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (a % b == 0)
        cout << "Y\n";
    else
        cout << "N\n";
    
    return 0;
}