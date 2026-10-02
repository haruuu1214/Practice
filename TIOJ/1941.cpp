#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 1e18;

signed main()
{
    IOS
    
    int n;
    cin >> n;
    int a, b;
    multiset <int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        st.insert(a);
        auto it = st.upper_bound(b);
        if (st.upper_bound(b) != st.end())
            st.erase(it);
    }
    cout << st.size() << "\n";
    
    return 0;
}