#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define STL(x) for (auto &HEHE : x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int P = 1e6 + 3;
const int M = 1e9 + 7;

vector <int> G[100005];

int get_hash(int v, int p)
{
    vector <int> vec;
    for (int u : G[v]) {
        if (u == p) continue;
        vec.push_back(get_hash(u, v));
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int cnt = 1, mul = 1;
    for (int i : vec) {
        mul *= P;
        mul %= M;
        cnt += i * i % M + i * mul % M;
        cnt %= M;
    }
    return cnt;
}

signed main()
{
    IOS
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int rh[2];
        for (int l = 0; l < 2; l++) {
            for (int i = 1; i <= n; i++)
                G[i].clear();
            int a, b;
            for (int i = 1; i <= n - 1; i++) {
                cin >> a >> b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
            rh[l] = get_hash(1, -1);
        }
        if (rh[0] == rh[1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}