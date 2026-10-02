#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 100005;

signed main()
{
    IO
    
    int a, b;
    cin >> a >> b;
    if (a > b) {
        for (int i = a; i >= b; i--) {
            for (int t = 1; t <= i; t++)
                cout << '*';
            cout << "\n";
        }
    } else {
        for (int i = a; i <= b; i++) {
            for (int t = 1; t <= i; t++)
                cout << '*';
            cout << "\n";
        }
    }
    
    return 0;
}