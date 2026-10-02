#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


struct item {
    int xl, xr, yl, yr;
};
const int N = 405;
int pre[N][N];
int t[N][N];
int mul[105];

signed main()
{
    IO
    
    mul[0] = 1;
    for (int i = 1; i <= 60; i++)
        mul[i] = mul[i - 1] * 2;
    
    int n;
    int a, b, c, d;
    while (cin >> n) {
        if (!n) break;
        fill(&t[0][0], &t[0][0] + N * N, 0);
        vector <int> x;
        vector <int> y;
        vector <item> input;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b >> c >> d;
            ++a, ++b;
            input.push_back({a, b, c, d});
            x.push_back(a);
            if (c + 1 <= 10000)
            x.push_back(c + 1);
            y.push_back(b);
            if (d + 1 <= 10000)
                y.push_back(d + 1);
        }
        x.push_back(1);
        y.push_back(1);
        x.push_back(10000);
        y.push_back(10000);
        sort(x.begin(), x.end());
        x.resize(unique(x.begin(), x.end()) - x.begin());
        sort(y.begin(), y.end());
        y.resize(unique(y.begin(), y.end()) - y.begin());
        int h = x.size(), w = y.size();

        int x1, y1, x2, y2;
        for (auto &[al, bl, ar, br] : input) {
            x1 = lower_bound(x.begin(), x.end(), al) - x.begin();
            y1 = lower_bound(y.begin(), y.end(), bl) - y.begin();
            x2 = lower_bound(x.begin(), x.end(), ar + 1) - x.begin();
            y2 = lower_bound(y.begin(), y.end(), br + 1) - y.begin();
            t[x1][y1]++;
            if (br + 1 <= 10000)
                t[x1][y2]--;
            if (ar + 1 <= 10000)
                t[x2][y1]--;
            if (ar + 1 <= 10000 && br + 1 <= 10000)
                t[x2][y2]++;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!i && !j)
                    pre[i][j] = t[i][j];
                else if (!i)
                    pre[i][j] = pre[i][j - 1] + t[i][j];
                else if (!j)
                    pre[i][j] = pre[i - 1][j] + t[i][j];
                else
                    pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + t[i][j];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == h - 1 && j == w - 1)
                    ans += mul[pre[i][j]];
                else if (i == h - 1)
                    ans += mul[pre[i][j]] * (y[j + 1] - y[j]);
                else if (j == w - 1)
                    ans += mul[pre[i][j]] * (x[i + 1] - x[i]);
                else
                    ans += mul[pre[i][j]] * (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}