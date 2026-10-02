#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;

    int cnt = 2;
    for (int i = 2; i <= n; i++)
        cnt += i;
    
    cout << cnt << "\n";
    
    return 0;
}