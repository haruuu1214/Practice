#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[200005];
int pre[200005];

signed main() {
    IO;

    int n, low, up;

    cin >> n >> low >> up;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int mx = -INF;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && i - dq.front() > up)
            dq.pop_front();

        if (i - low >= 0) {
            while (!dq.empty() && pre[dq.back()] >= pre[i - low])
                dq.pop_back();
            dq.push_back(i - low);
        }

        if (!dq.empty() && low <= i - dq.front() && i - dq.front() <= up)
            mx = max(mx, pre[i] - pre[dq.front()]);
    }

    cout << mx << "\n";

    return 0;
}