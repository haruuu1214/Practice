#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
 
const int mod = 1e9 + 7;
const int INF = 1e18;
 
int ten[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
bitset <987654321> vis;
 
int swap(int code, int i, int j) {
    int a, b;
    a = (code / ten[i]) % 10;
    b = (code / ten[j]) % 10;
    code += (b - a) * ten[i];
    code += (a - b) * ten[j];
    return code;
}
 
signed main()
{
    IOS
    
    int a[10], x = 0;
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        x = x * 10 + a[i];
    }
 
    queue <pii> Q;
    /// <permutation, steps>
    Q.push({x, 0});
    vis[x] = 1;
    while (!Q.empty()) {
        int perm = Q.front().first;
        int step = Q.front().second;
        if (perm == 123456789) {
            cout << step << "\n";
            return 0;
        }
        Q.pop();
        for (int i = 0; i < 9; i++) {
            if (i % 3 < 2) {
                int j = i + 1;
                perm = swap(perm, i, j);
                if (!vis[perm]) {
                    Q.push({perm, step + 1});
                    vis[perm] = 1;
                }
                perm = swap(perm, i, j);
            }
            if (i + 3 < 9) {
                int j = i + 3;
                perm = swap(perm, i, j);
                if (!vis[perm]) {
                    Q.push({perm, step + 1});
                    vis[perm] = 1;
                }
                perm = swap(perm, i, j);
            }
        }
    }
 
    return 0;
}
