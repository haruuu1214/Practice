#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    IO;

    int n, m;
    cin >> n >> m;
    int x;

    vector <int> station;

    int id = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (id < x)
            station.push_back(++id);
        auto it = find(station.begin(), station.end(), x);
        int pop_amount = (station.end() - it) - 1;
        if (pop_amount > m) {
            cout << "no\n";
            return 0;
        } else {
            station.erase(it);
        }
    }
    cout << "yes\n";
    
    return 0;
}