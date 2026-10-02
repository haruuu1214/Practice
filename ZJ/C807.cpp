#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    cin >> n;

    set<int> s;

    int op, a, b;
    for (i = 1; i <= n; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a;
            s.insert(a);
        } else {
            cin >> a >> b;

            auto l = s.lower_bound(a);
            auto r = s.upper_bound(b);
            s.erase(l, r);  /// [l, r)
        }
        if (s.empty()) {
            cout << 0 << "\n";
            continue;
        }

        int mn = *s.begin();
        int mx = *s.rbegin();
        if (mn == mx)
            cout << 1 << " " << mn << "\n";
        else
            cout << 2 << " " << mn << " " << mx << "\n";
    }

    return 0;
}