#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int now[10];
int N;
int t;

bool decode(int x)
{
    for (int i = 0; i < N; i++) {
        now[i] = x % 51;
        x /= 51;
        if (now[i] == t) return true;
    }
    return false;
}

int encode()
{
    int res = 0;
    for (int i = N - 1; i >= 0; i--) {
        res = res * 51 + now[i];
    }
    return res;
}

signed main()
{
    IOS
    
    int a[10];
    cin >> N;
    int mx = 0;
    int g = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        mx = max(mx, a[i]);
    }
    cin >> t;
    if (t % g != 0 || mx < t) {
        cout << "-1\n";
        return 0;
    }

    map <int, int> mp;
    queue <int> Q;
    Q.push(0); mp[0] = 0;
    while (!Q.empty()) {
        int code = Q.front();
        int step = mp[code];
        Q.pop();
        /// check
        if (decode(code)) {
            cout << mp[code] << "\n";
            return 0;
        }

        /// operator 1
        for (int i = 0; i < N; i++) {
            if (now[i] == 0) {
                int tmp = now[i];
                now[i] = a[i];
                int res = encode();
                now[i] = tmp;
                if (mp.find(res) == mp.end()) {
                    mp[res] = step + 1;
                    Q.push(res);
                }
            }
        }
        /// operator 2
        for (int i = 0; i < N; i++) {
            if (now[i] > 0) {
                int tmp = now[i];
                now[i] = 0;
                int res = encode();
                now[i] = tmp;
                if (mp.find(res) == mp.end()) {
                    mp[res] = step + 1;
                    Q.push(res);
                }
            }
        }
        /// operator 3
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (now[i] == 0) continue;
                int water = min(now[i], a[j] - now[j]);
                if (water == 0) continue;
                int tmp = now[i];
                now[i] -= water;
                now[j] += water;
                int res = encode();
                now[i] += water;
                now[j] -= water;
                if (mp.find(res) == mp.end()) {
                    mp[res] = step + 1;
                    Q.push(res);
                }
            }
        }
    }
    cout << "-1\n";
    
    return 0;
}