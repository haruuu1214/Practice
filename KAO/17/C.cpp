#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;



const int N = 200005;

int d[N];

char num[30];
char bigc[30];
char smallc[30];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 10; i++) num[i] = '0' + i;
    for (int i = 0; i < 26; i++) bigc[i] = 'A' + i;
    for (int i = 0; i < 26; i++) smallc[i] = 'a' + i;

    for (int k = 0; k < b.size(); k++) {
        if (b[k] == c[k]) continue;
        for (int i = 0; i < 10; i++)
            if (num[i] == b[k])
                num[i] = c[k];
        for (int i = 0; i < 26; i++)
            if (bigc[i] == b[k])
                bigc[i] = c[k];
        for (int i = 0; i < 26; i++)
            if (smallc[i] == b[k])
                smallc[i] = c[k];
    }

    for (int i = 0; i < a.size(); i++) {
        if ('0' <= a[i] && a[i] <= '9')
            a[i] = num[a[i] - '0'];
        else if ('a' <= a[i] && a[i] <= 'z')
            a[i] = smallc[a[i] - 'a'];
        else
            a[i] = bigc[a[i] - 'A'];
    }

    cout << a << "\n";
    
    return 0;
}