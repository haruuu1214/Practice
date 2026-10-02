#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    set <string> st;

    string s = "";
    for (int i = (int)s2.length() - 1; i >= 0; i--) {
        s = s2[i] + s;
        st.insert(s);
    }

    s = "";
    int ans = 0;
    for (int i = 0; i < s1.length(); i++) {
        s = s + s1[i];
        if (st.find(s) != st.end())
            ans = max(ans, i + 1);
    }
    cout << ans << "\n";
    
    return 0;
}