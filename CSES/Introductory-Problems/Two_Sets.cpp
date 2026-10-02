#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 1000005;
bool chs[N];

signed main() {
    IO;
    int n;
    cin >> n;
    if ((n * (n + 1) / 2) % 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int tar = n * (n + 1) / 4;
    int cur = 0, cnt = 0;
    for (int i = n; i >= 1; i--)
        if (cur + i <= tar) {
            chs[i] = true;
            cur += i;
            cnt += 1;
        }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++)
        if (chs[i])
            cout << i << " ";
    cout << "\n";
    cout << n - cnt << "\n";
    for (int i = 1; i <= n; i++)
        if (! chs[i])
            cout << i << " ";
    cout << "\n";
    return 0;
}