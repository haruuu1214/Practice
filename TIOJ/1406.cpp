#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;
int a[N], b[N];
int n;

bool check(int x) {
    int less = b[1] - x;
    for (int i = 2; i <= n; i++) {
        if (less >= 0)
            less = max(0ll, less - (a[i] - a[i - 1]));
        else
            less -= a[i] - a[i - 1];
        less += b[i] - x;
    }
    return (less >= 0);
}

signed main()
{
    IO;
    
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        int l = 0, r = 1e13;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        cout << l << "\n";
    }
    
    return 0;
}