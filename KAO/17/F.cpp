#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 200005;
int a[N];

signed main() {
    IO;
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (2 * k + 1 >= n) {
        cout << a[(n + 1) / 2] << "\n";
        return 0;
    }

    int cnt = 0;
    int num = n % (2 * k + 1);
    if (num == 0) {
        for (int i = k + 1; i <= n; i += 2 * k + 1)
            cnt += a[i];
    } else {
        int head;
        if (num < k) {
            head = num;
        } else {
            head = k;
        }
        for (int i = head; i <= n; i += 2 * k + 1)
            cnt += a[i];
    }
    cout << cnt << "\n";

    return 0;
}
/*
6 2 1
3 3 3 1 3 2
-> 6

3 8 1
6 9 6
-> 12

5 2 1
3 5 4 5 3
-> 8

7 1 2
2 2 3 2 3 2 2
-> 4

7 7 1
7 7 1 1 2 2 2
-> 10
*/