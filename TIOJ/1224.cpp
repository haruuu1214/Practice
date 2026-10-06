#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;


int add[4 * 100005];
int seg[4 * 100005];
vector <int> t;
vector <int> pos;

void pull(int node, int l, int r)
{
    int mid = (l + r) >> 1;
    if (add[node] > 0)
        seg[node] = (pos[r] - pos[l]);
    else
        seg[node] = (add[(node << 1)] > 0 ? pos[mid] - pos[l] : seg[(node << 1)]) +
                    (add[((node << 1) | 1)] > 0 ? pos[r] - pos[mid] : seg[((node << 1) | 1)]);
}

void add_tag(int node, int l, int r, int ql, int qr, int val)
{
    if (l == r)
        return;
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr) {
        add[node] += val;
    } else {
        int mid = (l + r) >> 1;
        add_tag((node << 1), l, mid, ql, qr, val);
        add_tag(((node << 1) | 1), mid, r, ql, qr, val);
    }

    pull(node, l, r);
}

int get_id(int x)
{
    return lower_bound(pos.begin(), pos.end(), x) - pos.begin();
}

signed main()
{
    IO;
    
    int n;
    cin >> n;

    vector <pair<int, pii>> pls;
    vector <pair<int, pii>> sub;
    int a, b, c, d;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        t.push_back(a);
        t.push_back(b);
        pos.push_back(c);
        pos.push_back(d);
        pls.push_back({a, {c, d}});
        sub.push_back({b, {c, d}});
    }

    t.push_back(-1);

    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    sort(pls.begin(), pls.end(), greater<pair<int, pii>>());
    sort(sub.begin(), sub.end(), greater<pair<int, pii>>());

    int ans = 0;
    for (int i = 1; i < t.size(); i++) {
        pull(1, 0, pos.size() - 1);
        ans += (t[i] - t[i - 1]) * seg[1];

        while (!pls.empty() && pls.back().first == t[i]) {
            int l = get_id(pls.back().second.first);
            int r = get_id(pls.back().second.second);
            add_tag(1, 0, pos.size() - 1, l, r, +1);
            pls.pop_back();
        }

        while (!sub.empty() && sub.back().first == t[i]) {
            int l = get_id(sub.back().second.first);
            int r = get_id(sub.back().second.second);
            add_tag(1, 0, pos.size() - 1, l, r, -1);
            sub.pop_back();
        }
    }
    cout << ans << "\n";

    return 0;
}