#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define STL(x) for (auto &HEHE : x) cout << HEHE << " "; cout << "\n";
using namespace std;

const int p = 1e6 + 3;
const int mod = 1e9 + 7; /// 不能超過 3e9 -> 會 overflow

int hash(string &s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res *= p;
        res += s[i] - 'a' + 1;
        res %= mod;
    }
    return res;
}

int pow_p[2000005];
vector <int> rh;
void build(string &s) {
    rh.resize(s.size() + 1);
    pow_p[0] = 1;
    for (int i = 1; i <= s.size(); i++)
        pow_p[i] = (pow_p[i - 1] * p) % mod;
    
    rh[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++) {
        rh[i] = rh[i - 1] * p + (s[i] - 'a' + 1);
        rh[i] %= mod;
    }
}

int query(int l, int r) {
    int res = rh[r] - (l > 0 ? rh[l - 1] * pow_p[r - l + 1] : 0);
    res = (res % mod + mod) % mod;
    return res;
}

signed main() {
    IOS
    
    string input;
    cin >> input;
    int len = input.size();
    string s = input + input;
    build(s);

    int ans_id = -1;
    for (int i = 0; i < len; i++) {
        /// 枚舉頭
        if (ans_id == -1) {
            ans_id = i;
            continue;
        }
        int l = -1, r = len;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (query(i, i + mid) == query(ans_id, ans_id + mid))
                l = mid;
            else
                r = mid;
        }
        if (r == len) /// 一模一樣
            continue;
        if (s[i + r] < s[ans_id + r]) {
            ans_id = i;
        }
    }
    for (int i = ans_id; i < ans_id + len; i++)
        cout << s[i];
    cout << "\n";
    
    return 0;
}