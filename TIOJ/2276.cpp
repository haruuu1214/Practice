#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;

const int N = 100005;

bool must_do[10][10];

signed main()
{
    IO
    
    int k, x;
    for (int i = 1; i <= 6; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> x;
            must_do[i][x] = true;
        }
    }

    vector <int> v(10);
    
    int ans = 0;
    for (int a = 1; a <= 6; a++) {
        for (int b = 1; b <= 6; b++) {
            for (int c = 1; c <= 6; c++) {
                for (int d = 1; d <= 6; d++) {
                    for (int e = 1; e <= 6; e++) {
                        for (int f = 1; f <= 6; f++) {
                            v[1] = a;
                            v[2] = b;
                            v[3] = c;
                            v[4] = d;
                            v[5] = e;
                            v[6] = f;
                            bool check = true;
                            for (int i = 1; i <= 6; i++)
                                if (must_do[v[i]][i]) {
                                    check = false;
                                    break;
                                }
                            if (check)
                                ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}