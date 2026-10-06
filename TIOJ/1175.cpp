#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[200005];
int dp[200005];
int from[200005];

signed main()
{
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <int> tmp;
    vector <int> id; id.push_back(0);
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
        if (idx == tmp.size()) {
            tmp.push_back(a[i]);
            id.push_back(i);
            dp[i] = idx;
            from[i] = id[idx];
        } else {
            tmp[idx] = a[i];
            id[idx + 1] = i;
            dp[i] = idx;
            from[i] = id[idx];
        }
    }
    cout << tmp.size() << "\n";

    return 0;
}