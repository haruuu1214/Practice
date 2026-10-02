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

struct node
{
    node* link[2] = {nullptr};
    bool exist(int val) {
        return (link[val] != nullptr);
    }
    void put(int val, node* _node) {
        link[val] = _node;
    }
    node* get(int val) {
        return link[val];
    }
};

struct Trie
{
    node* root;
    Trie() {
        root = new node();
    }
    void update(int x) {
        node* now = root;
        for (int i = 30; i >= 0; i--) {
            if (x & (1 << i)) {
                if (!now->exist(1))
                    now->put(1, new node());
                now = now->get(1);
            } else {
                if (!now->exist(0))
                    now->put(0, new node());
                now = now->get(0);
            }
        }
    }
    int query_max(int x) {
        node* now = root;
        int mx = 0;
        for (int i = 30; i >= 0; i--) {
            bool nowbit = (x & (1 << i));
            int target = nowbit ^ 1;
            if (now->exist(target)) {
                mx += 1 << i;
                now = now->get(target);
            } else {
                now = now->get(nowbit);
            }
        }
        return mx;
    }
};

signed main()
{
    int n, x, mx = 0, pre = 0;
    cin >> n;
    Trie T;
    T.update(0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        pre = pre ^ x;
        mx = max(mx, T.query_max(pre));
        T.update(pre);
    }
    cout << mx << "\n";
    
    return 0;
}