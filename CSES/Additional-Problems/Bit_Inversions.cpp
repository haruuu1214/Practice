#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

bool a[200005];
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Segment_tree
{
    int N;
    vector <int> info;
    vector <int> pre;
    vector <int> suf;
    Segment_tree(int n) : N(n), info(4 * n + 5), pre(4 * n + 5), suf(4 * n + 5) {}
    Segment_tree(vector <int> init) : Segment_tree(init.size()) {
        function <void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                info[node] = pre[node] = suf[node] = init[l - 1];
                return;
            }
            int mid = (l + r) >> 1;
            build((node << 1), l, mid);
            build(((node << 1) | 1), mid + 1, r);
            pull(node, l, r);
        };
        build(1, 1, N);
    }
    void pull(int node, int l, int r) {
        int mid = (l + r) >> 1;
        int lc = (node << 1);
        int rc = ((node << 1) | 1);
        info[node] = max({suf[lc] + pre[rc], info[lc], info[rc]});
        pre[node] = pre[lc] + (pre[lc] == mid - l + 1 ? pre[rc] : 0ll);
        suf[node] = suf[rc] + (suf[rc] == r - mid     ? suf[lc] : 0ll);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            info[node] = pre[node] = suf[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update((node << 1), l, mid, idx, val);
        else
            update(((node << 1) | 1), mid + 1, r, idx, val);
        pull(node, l, r);
    }
    void update(int idx, int val) {
        update(1, 1, N, idx, val);
    }
};

struct Segment_tree2
{
    int N;
    vector <int> info;
    vector <int> pre;
    vector <int> suf;
    Segment_tree2(int n) : N(n), info(4 * n + 5), pre(4 * n + 5), suf(4 * n + 5) {}
    Segment_tree2(vector <int> init) : Segment_tree2(init.size()) {
        function <void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                info[node] = pre[node] = suf[node] = init[l - 1];
                return;
            }
            int mid = (l + r) >> 1;
            build((node << 1), l, mid);
            build(((node << 1) | 1), mid + 1, r);
            pull(node, l, r);
        };
        build(1, 1, N);
    }
    void pull(int node, int l, int r) {
        int mid = (l + r) >> 1;
        int lc = (node << 1);
        int rc = ((node << 1) | 1);
        info[node] = max({suf[lc] + pre[rc], info[lc], info[rc]});
        pre[node] = pre[lc] + (pre[lc] == mid - l + 1 ? pre[rc] : 0ll);
        suf[node] = suf[rc] + (suf[rc] == r - mid     ? suf[lc] : 0ll);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            info[node] = pre[node] = suf[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update((node << 1), l, mid, idx, val);
        else
            update(((node << 1) | 1), mid + 1, r, idx, val);
        pull(node, l, r);
    }
    void update(int idx, int val) {
        update(1, 1, N, idx, val);
    }
};

signed main()
{
    IOS
    
    string input;
    cin >> input;
    int q;
    cin >> q;

    int n = input.size();
    vector <int> v1, v2;
    for (int i = 0; i < n; i++) {
        a[i + 1] = (input[i] == '1');
        if (input[i] == '1') {
            v1.push_back(0);
            v2.push_back(1);
        } else {
            v1.push_back(1);
            v2.push_back(0);
        }
    }

    Segment_tree S0(v1);
    Segment_tree2 S1(v2);
    
    int idx;
    while (q--) {
        cin >> idx;
        if (a[idx] == 1) {
            a[idx] = 0;
            S0.update(idx, 1);
            S1.update(idx, 0);
        } else {
            a[idx] = 1;
            S0.update(idx, 0);
            S1.update(idx, 1);
        }
        cout << max(S0.info[1], S1.info[1]) << " ";
    }
    
    return 0;
}