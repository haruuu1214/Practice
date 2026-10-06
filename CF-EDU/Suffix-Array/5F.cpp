#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void debug() { cerr << endl; }
template <typename T, typename ...U>
void debug(T i, U ...j) { cerr << i << ' ', debug(j...); }
#define test(...) debug("[" #__VA_ARGS__ "]:", __VA_ARGS__)

const int N = 4e5 + 5;
struct Suffix_Array {
    vector<int> sa, rk, lcp, c;
    vector<int> tmp[2];
    vector<vector<int>> st;
    Suffix_Array(int n) : sa(n), rk(n), lcp(n), c(max(256ll, n)), tmp{vector<int>(n), vector<int>(n)} {}
    void buildSA(const string &s) {
        vector<int> &x = tmp[0], &y = tmp[1];
        int m = 256, n = s.size();
        for (int i = 0; i < m; ++i) c[i] = 0;
        for (int i = 0; i < n; ++i) c[x[i] = (unsigned char)s[i]]++;
        for (int i = 1; i < m; ++i) c[i] += c[i - 1];
        for (int i = n - 1; ~i; --i) sa[--c[x[i]]] = i;
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < m; ++i) c[i] = 0;
            for (int i = 0; i < n; ++i) c[x[i]]++;
            for (int i = 1; i < m; ++i) c[i] += c[i - 1];
            int p = 0;
            for (int i = n - k; i < n; ++i) y[p++] = i;
            for (int i = 0; i < n; ++i) if (sa[i] >= k)
                y[p++] = sa[i] - k;
            for (int i = n - 1; ~i; --i)
                sa[--c[x[y[i]]]] = y[i];
            y[sa[0]] = p = 0;
            for (int i = 1; i < n; ++i) {
                int a = sa[i], b = sa[i - 1];
                if (!(x[a] == x[b] && a + k < n && b + k < n && x[a + k] == x[b + k])) p++;
                y[sa[i]] = p;
            }
            if (n == p + 1) break;
            swap(x, y), m = p + 1;
        }
    }
    void buildLCP(const string &s) {
        // lcp[i] = LCP(sa[i - 1], sa[i])
        // lcp(i, j) = query_lcp_min [rk[i] + 1, rk[j] + 1)
        int n = s.length(), val = 0;
        for (int i = 0; i < n; ++i) rk[sa[i]] = i;
        for (int i = 0; i < n; ++i) {
            if (!rk[i]) lcp[rk[i]] = 0;
            else {
                if (val) val--;
                int p = sa[rk[i] - 1];
                while (val + i < n && val + p < n && s[val + i] == s[val + p]) val++;
                lcp[rk[i]] = val;
            }
        }
    }
    void buildST(int n) {
        // st[j][i] = min(lcp[i], ..., lcp[i + 2^j - 1])
        st.assign(__lg(n) + 1, vector<int>(n));
        for (int i = 0; i < n; ++i) st[0][i] = lcp[i];
        for (int j = 1; (1 << j) <= n; ++j)
            for (int i = 0; i + (1 << j) <= n; ++i)
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }
    int queryMin(int l, int r) {
        // min of lcp[l, r)
        int j = __lg(r - l);
        return min(st[j][l], st[j][r - (1 << j)]);
    }
    int get_lcp(int l1, int r1, int l2, int r2) {
        // LCP(s[l1, r1), s[l2, r2))
        int len = min(r1 - l1, r2 - l2);
        if (len <= 0) return 0;
        if (l1 == l2) return len;
        int a = rk[l1], b = rk[l2];
        if (a > b) swap(a, b);
        return min(len, queryMin(a + 1, b + 1));
    }
};

signed main() {
	IO;
    string s;
    cin >> s;
    int n = sz(s);
    Suffix_Array sa(n), sa_rev(n);
    sa.buildSA(s);
    sa.buildLCP(s);
    sa.buildST(n);
    string rev = "";
    rev = string(s.rbegin(), s.rend());
    sa_rev.buildSA(rev);
    sa_rev.buildLCP(rev);
    sa_rev.buildST(n);
    int ans = 1;
    for (int gap = 1; gap < n; gap++) {
        for (int j = 0; j + gap < n; j += gap) {
            int res1 = sa.get_lcp(j, n, j + gap, n);
            int res2 = sa_rev.get_lcp(n - j - gap, n, n - j, n);
            int len = res1 + res2 + gap;
            ans = max(ans, len / gap);
        }
    }
    cout << ans << '\n';
}