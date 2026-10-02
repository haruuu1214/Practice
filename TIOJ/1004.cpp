#include <bits/stdc++.h>
using namespace std;

bool killed[55];
int nxt[55];

signed main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n - 1; i++) nxt[i] = i + 1;
    nxt[n] = 1;

    bool jump = true;
    int cnt = 0, now = 1;
    int pre = 0;
    while (cnt < n) {
        if (now == n + 1) {
            now = 1;
            continue;
        }
        if (killed[now] == true) {
            now++;
            continue;
        }
        if (jump == true) {
            now++;
            jump = false;
            continue;
        }

        killed[now] = true;
        nxt[pre] = now;
        pre = now;
        now++;
        cnt++;
        jump = true;
    }

    cout << now - 1 << "\n";
    
    return 0;
}