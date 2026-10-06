#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int a[200005];
int cnt[200005];

signed main()
{
    IO;
    
    int n;
    cin >> n;

    for (int i = 1; i <= n - 2; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i])
            pq.push(i);
    }

    for (int i = 1; i <= n - 2; i++) {
        cout << pq.top() << " " << a[i] << "\n";
        pq.pop();
        cnt[a[i]]--;
        if (!cnt[a[i]])
            pq.push(a[i]);
    }

    int t = pq.top(); pq.pop();
    cout << t << " " << pq.top() << "\n";

    return 0;
}