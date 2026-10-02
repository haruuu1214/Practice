#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

set <string> S;

signed main()
{
    IOS
    
    string input;
    cin >> input;
    
    string tmp = "";
    for (int i = (int)input.size() - 1; i >= 0; i--) {
        tmp = input[i] + tmp;
        S.insert(tmp);
    }
    
    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        string input = "";
        cin >> input;
        int ans = -1;
        string t = "";
        for (int j = 0; j < (int)input.size(); j++) {
            t = t + input[j];
            if (S.find(t) != S.end()) {
                int x = min((int)input.size() - j - 1, j + 1);
                ans = max(ans, x);
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}