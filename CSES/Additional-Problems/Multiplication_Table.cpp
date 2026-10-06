#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

bool check(int n, int k)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i > k)
            break;
        cnt += min(n, k / i);
        if (cnt >= n * n / 2 + 1)
            return false;
    }
    return true;
}

signed main()
{
    IO;
    
    int n;
    cin >> n;

    int l = 0, r = n * n + 1;

    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(n, mid))
            l = mid;
        else
            r = mid;
    }
    
    cout << r << "\n";

    
    return 0;
}