#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 2000005;

ll a[N], dp[N];
int pre[N];
ll prea[N];

signed main()
{
    IO
    
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) prea[i] = prea[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i - 1] - '0');

    deque <int> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && pre[i] - pre[dq.front() - 1] > k)
            dq.pop_front();
        if (dq.empty()) {
            dp[i] = a[i];
            dq.push_back(i);
        } else {
            dp[i] = max(a[i], prea[i] - prea[dq.front() - 1]);
            while (!dq.empty() && prea[dq.back() - 1] >= prea[i - 1])
                dq.pop_back();
            dq.push_back(i);
        }
    }
    ll mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, dp[i]);
    cout << mx << "\n";


    return 0;
}