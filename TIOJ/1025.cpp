/// @brief ZJ B053
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N;
bool chR[10][10], chC[10][10], chS[10][10];
/// @brief  第 R 行 第 C 列 第 S 個正方形
int a[10][10];
int g[82];
int cnt = 0;

void solve(int id)
{
    if (id == (N * N) * (N * N)) {
        int idx = 0;
        for (int i = 0; i < N * N; i++) {
            for (int j = 0; j < N * N; j++) {
                cout << g[idx++] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        cnt++;
    }
    int R = id % (N * N), C = id / (N * N), S = R / N * N + C / N;
    if (a[R][C] != 0) {
        solve(id + 1);
        return;
    }
/// @brief  第 R 行 第 C 列 第 S 個正方形
    for (int k = 1; k <= N * N; k++) {
        if (!chR[R][k] && !chC[C][k] && !chS[S][k]) {
            chR[R][k] = chC[C][k] = chS[S][k] = true;
            g[id] = k;
            solve(id + 1);
            chR[R][k] = chC[C][k] = chS[S][k] = false;
        }
    }
}

signed main()
{
    IO;
    
    N = 3;
    fill(&chR[0][0], &chR[0][0] + 10 * 10, 0);
    fill(&chC[0][0], &chC[0][0] + 10 * 10, 0);
    fill(&chS[0][0], &chS[0][0] + 10 * 10, 0);

    for (int j = 0; j < N * N; j++) {
        for (int i = 0; i < N * N; i++) {
            cin >> a[i][j];
        }
    }
    bool fail = false;
    for (int id = 0; id < (N * N) * (N * N); id++) {
        int R = id % (N * N), C = id / (N * N), S = R / N * N + C / N;
        int val = a[R][C];
        if (a[R][C] == 0) continue;
        if (chR[R][val] || chC[C][val] || chS[S][val]) {
            fail = true;
            break;
        }
        g[id] = val;
        chR[R][val] = chC[C][val] = chS[S][val] = true;
    }

    if (!fail)
        solve(0);
    
    cout << "there are a total of " << cnt << " solution(s)." << "\n";
    
    return 0;
}