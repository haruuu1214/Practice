#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;


const int N = 100005;
vector<int> ti;
pii a[N];
int n, k;

bool check(int x) {
    int cnt = 0;
    int cur = 0;
    int id = 0;
    multiset<int> not_use_r;
    for (int t : ti) {
        while (id < n && a[id].first == t) {
            not_use_r.insert(a[id].second);
            id += 1;
            cur += 1;
        }
        while (! not_use_r.empty() && * not_use_r.begin() == t) {
            not_use_r.erase(not_use_r.begin());
            cur -= 1;
        }
        while (! not_use_r.empty() && cur > x) {
            not_use_r.erase(not_use_r.find(* not_use_r.rbegin()));
            cur -= 1;
            cnt += 1;
        }
        if (cur > x || cnt > k)
            return false;
    }
    return true;
}

signed main() {
    IO;
    
    cin >> n >> k;
    FOR (i, 0, n - 1) {
        cin >> a[i].first >> a[i].second;
        ti.push_back(a[i].first);
        ti.push_back(a[i].second);
    }
    sort(ti.begin(), ti.end());
    ti.resize(unique(ti.begin(), ti.end()) - ti.begin());
    sort(a, a + n);

    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << "\n";
    
    return 0;
}