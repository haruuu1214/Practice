#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


const int N = 100005;

signed main() {
    IO;
    
    string s;
    while (cin >> s) {
        int a[2] = {0, 0};
        int id = 0;
        FOR (tt, 1, 9) {
            FOR (turn, 0, 1) {
                int now[3] = {0, 0, 0};
                FOR (t, 1, 3) {
                    while (s[id] != 'K' && s[id] != 'O') {
                        if (s[id] == 'W') {
                            if (now[2] && now[1] && now[0]) { now[2] -= 1; a[turn] += 1; }
                            if (now[1] && now[0]) { now[1] -= 1; now[2] += 1; }
                            if (now[0]) { now[0] -= 1; now[1] += 1; }
                            now[0] += 1;
                        } else if (s[id] == 'S') {
                            if (now[2]) { now[2] -= 1; a[turn] += 1; }
                            if (now[1]) { now[1] -= 1; now[2] += 1; }
                            if (now[0]) { now[0] -= 1; now[1] += 1; }
                            now[0] += 1;
                        } else if (s[id] == 'D') {
                            if (now[2]) { now[2] -= 1; a[turn] += 1; }
                            if (now[1]) { now[1] -= 1; a[turn] += 1; }
                            if (now[0]) { now[0] -= 1; now[2] += 1; }
                            now[1] += 1;
                        } else if (s[id] == 'T') {
                            if (now[2]) { now[2] -= 1; a[turn] += 1; }
                            if (now[1]) { now[1] -= 1; a[turn] += 1; }
                            if (now[0]) { now[0] -= 1; a[turn] += 1; }
                            now[2] += 1;
                        } else {
                            if (now[2]) { now[2] -= 1; a[turn] += 1; }
                            if (now[1]) { now[1] -= 1; a[turn] += 1; }
                            if (now[0]) { now[0] -= 1; a[turn] += 1; }
                            a[turn] += 1;
                        }
                        id += 1;
                    }
                    id += 1;
                }
            }
        }
        cout << a[0] << " " << a[1] << "\n";
    }
    
    return 0;
}