#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

const int N = 100005;

signed main()
{
    IOS
    
    int prea = -1, preb = -1;
    int n, a, b;
    int idx = 1;
    
    vector <pair<int, pii>> ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (prea == -1) {
            prea = a, preb = b;
            idx = 1;
        } else if (b < prea || preb < a) {
            ans.push_back({prea, {idx, i - 1}});
            idx = i;
            prea = a, preb = b;
        } else {
            prea = max(prea, a);
            preb = min(preb, b);
        }
    }

    ans.push_back({prea, {idx, n}});
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }

    return 0;
}