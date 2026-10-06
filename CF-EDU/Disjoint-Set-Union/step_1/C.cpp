#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n;
int pts[200005];
int dsu[200005];
int sz[200005];

int find(int x)
{
    if (dsu[x] == x) return x;
    return find(dsu[x]);
}

void join(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    dsu[y] = dsu[x];
    pts[y] -= pts[x];
    sz[x] += sz[y];
}

void add(int x, int val)
{
    x = find(x);
    pts[x] += val;
}

int get(int x)
{
    if (dsu[x] == x)
        return pts[x];
    return pts[x] + get(dsu[x]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        sz[i] = i;
        pts[i] = 0;
    }
    
    int a, b;
    string s;
    while (q--) {
        cin >> s;
        if (s[0] == 'j') {
            cin >> a >> b;
            join(a, b);
        } else if (s[0] == 'a') {
            cin >> a >> b;
            add(a, b);
        } else {
            cin >> a;
            cout << get(a) << "\n";
        }
    }
    
    return 0;
}