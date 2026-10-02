#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int N = 3000005;

const int p = 1e6 + 3;
const int mod = 1e9 + 7;
int pow_p[N];
vector <int> a_rh;
vector <int> b_rh;

int mul(int x, int y) {
    if (1ll * x * y >= mod)
        return (1ll * x * y) % mod;
    else
        return x * y;
}

int add(int x, int y) {
    if ((ll)x + y >= mod)
        return (ll)x + y - mod;
    else
        return x + y;
}

void build_a(string &s) {
    a_rh.resize(s.size() + 1);
    a_rh[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
        a_rh[i] = add(mul(a_rh[i - 1], p), (s[i] - 'a' + 1));
}

int query_a(int l, int r) {
    int res = add(a_rh[r], - (l > 0 ? mul(a_rh[l - 1], pow_p[r - l + 1]) : 0));
    return add(res, mod);
}

void build_b(string &s) {
    b_rh.resize(s.size() + 1);
    b_rh[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
        b_rh[i] = add(mul(b_rh[i - 1], p), (s[i] - 'a' + 1));
}

int query_b(int l, int r) {
    int res = add(b_rh[r], - (l > 0 ? mul(b_rh[l - 1], pow_p[r - l + 1]) : 0));
    return add(res, mod);
}

void solve() {
    string a, b;
    cin >> a >> b;

    int a_len = a.size();
    int b_len = b.size();

    vector <int> star;
    if (a[0] != '*') star.push_back(-1);
    for (int i = 0; i < a_len; i++)
        if (a[i] == '*') {
            star.push_back(i);
            a[i] = 'z' + 1;
        }

    build_a(a);
    build_b(b);
    int n = star.size();
    int starid = 1;

    for (int i = 0; i < b_len; i++) {
        while (starid < n && star[starid - 1] + 1 == star[starid])
            starid++;
        if (starid < n) {
            int len = star[starid] - star[starid - 1] - 1;
            if (i + len - 1 < b_len && query_a(star[starid - 1] + 1, star[starid] - 1) == query_b(i, i + len - 1)) {
                starid++;
                i += len - 1;
            } else if (star[starid - 1] == -1 || i + len - 1 >= b_len) {
                cout << "No\n";
                return;
            }
        } else {
            int len = a_len - star[starid - 1] - 1;
            if (i + len - 1 == b_len - 1 && query_a(star[starid - 1] + 1, a_len - 1) == query_b(i, i + len - 1)) {
                break;
            } else if (star[starid - 1] == -1 || i + len - 1 >= b_len - 1) {
                cout << "No\n";
                return;
            } else {
                i = b_len - len - 1;
            }
        }
        if (starid == n && star[n - 1] == a_len - 1)
            break;
    }
    cout << "Yes\n";
}
/*
3
*armstrong*armstrong*
neoarmstrongcyclonejetarmstrongcannon
a
ba
qq
qaq
*/

/*
3
*
aa
**
a
a*b
accb
*/

/*
1
*aaaaa
pppsqq
*/

/*
1
ab*bac
abac
*/

signed main() {
    IO;
    
    pow_p[0] = 1;
    for (int i = 1; i <= 3000000; i++)
        pow_p[i] = mul(pow_p[i - 1], p);
    
    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}