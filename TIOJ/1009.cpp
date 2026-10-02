#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string st1, st2;
    cin >> st1;
    cin >> st2;

    int h1 = (st1[0] - '0') * 10 + (st1[1] - '0');
    int m1 = (st1[3] - '0') * 10 + (st1[4] - '0');
    int s1 = (st1[6] - '0') * 10 + (st1[7] - '0');

    int h2 = (st2[0] - '0') * 10 + (st2[1] - '0');
    int m2 = (st2[3] - '0') * 10 + (st2[4] - '0');
    int s2 = (st2[6] - '0') * 10 + (st2[7] - '0');
    
    if (h1 * 3600 + m1 * 60 + s1 > h2 * 3600 + m2 * 60 + s2)
        h2 += 24;
    
    int h = h2 - h1;
    int m = m2 - m1;
    int s = s2 - s1;

    if (s < 0) {
        m--;
        s += 60;
    }
    if (m < 0) {
        h--;
        m += 60;
    }

    if (h < 10)
        cout << 0 << h;
    else
        cout << h;
    cout << ":";
    if (m < 10)
        cout << 0 << m;
    else
        cout << m;
    cout << ":";
    if (s < 10)
        cout << 0 << s;
    else
        cout << s;
    cout << "\n";

    return 0;
}