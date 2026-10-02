#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(p, a, b) for(int p = a; p <= b; p++)
using namespace std;

char a[3][3];

bool count_win(char c) {
    FOR (i, 0, 2) {
        bool fg = true;
        FOR (j, 0, 2)
            if (a[i][j] != c) {
                fg = false;
                break;
            }
        if (fg)
            return true;
    }
    FOR (j, 0, 2) {
        bool fg = true;
        FOR (i, 0, 2)
            if (a[i][j] != c) {
                fg = false;
                break;
            }
        if (fg)
            return true;
    }
    bool fg = true;
    FOR (i, 0, 2)
        if (a[i][i] != c) {
            fg = false;
            break;
        }
    if (fg)
        return true;
    fg = true;
    FOR (i, 0, 2)
        if (a[i][2 - i] != c) {
            fg = false;
            break;
        }
    if (fg)
        return true;
    return false;
}

signed main() {
    IO;
    
    FOR (i, 0, 2) FOR (j, 0, 2) cin >> a[i][j];

    int cnt1 = 0, cnt2 = 0;
    FOR (i, 0, 2) FOR (j, 0, 2) {
        if (a[i][j] == 'O')
            cnt1 += 1;
        else if (a[i][j] == 'X')
            cnt2 += 1;
        else if (a[i][j] != '.') {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    bool win1 = count_win('O'), win2 = count_win('X');
    if (win1 && win2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    if (cnt1 - cnt2 == 1) {
        if (win2)
            cout << "IMPOSSIBLE\n";
        else
            cout << "POSSIBLE\n";
    } else if (cnt1 == cnt2) {
        if (win1)
            cout << "IMPOSSIBLE\n";
        else
            cout << "POSSIBLE\n";
    } else {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    

    return 0;
}