#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


bool check_share_times(int day, int times, int amount) {
    int cnt = 0;
    int i = 1, now_share = day - 1;
    do {
        times -= i;
        i *= 2;
        now_share -= 1;
    } while (times - i > 0 && now_share - 1 > 0) ;
    amount -= (now_share + 1) * (i - times) + (now_share) * (times * 2);
    return (amount <= 0);
}
const int N = 100005;
int n, k;
int a[N];

bool check(int day) {
    int less = k;
    FOR (i, 1, n) {
        if (a[i] - day > 0) {
            int l = 0, r = 1e6;
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                if (check_share_times(day, mid, a[i]))
                    r = mid;
                else
                    l = mid;
            }
            less -= r;
        }
        if (less < 0) return false;
    }
    return true;
}

signed main() {
    IO;
    
    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];

    int l = -1, r = 1e9;
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
/*
1 2
24
*/