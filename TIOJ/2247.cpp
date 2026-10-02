#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
const int INF = 1e18;


int dis[26][26];

void add_edge(char a, char b) {
    dis[a - 'A'][b - 'A'] = dis[b - 'A'][a - 'A'] = 1;
}

void init() {
    fill(&dis[0][0], &dis[0][0] + 30 * 30, INF);
    add_edge('Q', 'W'); add_edge('Q', 'A');
    add_edge('A', 'W'); add_edge('A', 'S'); add_edge('A', 'Z');
    add_edge('Z', 'S'); add_edge('Z', 'X');
    add_edge('W', 'E'); add_edge('W', 'S');
    add_edge('S', 'E'); add_edge('S', 'D'); add_edge('S', 'X');
    add_edge('X', 'D'); add_edge('X', 'C');
    add_edge('E', 'R'); add_edge('E', 'D');
    add_edge('D', 'R'); add_edge('D', 'F'); add_edge('D', 'C');
    add_edge('C', 'F'); add_edge('C', 'V');
    add_edge('R', 'T'); add_edge('R', 'F');
    add_edge('F', 'T'); add_edge('F', 'G'); add_edge('F', 'V');
    add_edge('V', 'G'); add_edge('V', 'B');
    add_edge('T', 'Y'); add_edge('T', 'G');
    add_edge('G', 'Y'); add_edge('G', 'H'); add_edge('G', 'B');
    add_edge('B', 'H'); add_edge('B', 'N');
    add_edge('Y', 'U'); add_edge('Y', 'H');
    add_edge('H', 'U'); add_edge('H', 'J'); add_edge('H', 'N');
    add_edge('N', 'J'); add_edge('N', 'M');
    add_edge('U', 'I'); add_edge('U', 'J');
    add_edge('J', 'I'); add_edge('J', 'K'); add_edge('J', 'M');
    add_edge('M', 'K');
    add_edge('I', 'O'); add_edge('I', 'K');
    add_edge('K', 'O'); add_edge('K', 'L');
    add_edge('O', 'P'); add_edge('O', 'L');
    add_edge('L', 'P');
    for (int i = 0; i < 26; i++) dis[i][i] = 0;
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

const int N = 10005;
int dp[N][26][26];

signed main() {
    IO;
    
    init();

    int n;
    cin >> n;
    string s;
    cin >> s;

    fill(&dp[0][0][0], &dp[0][0][0] + N * 26 * 26, INF);
    dp[0]['F' - 'A']['J' - 'A'] = 0;
    for (int i = 0; i < n; i++) {
        int nxt = s[i] - 'A';
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (dp[i][j][k] == INF) continue;
                dp[i + 1][nxt][k] = min(dp[i + 1][nxt][k], dp[i][j][k] + dis[j][nxt]);
                dp[i + 1][j][nxt] = min(dp[i + 1][j][nxt], dp[i][j][k] + dis[k][nxt]);
            }
        }
    }
    int ans = INF;
    for (int j = 0; j < 26; j++) {
        for (int k = 0; k < 26; k++) {
            ans = min(ans, dp[n][j][k]);
        }
    }
    cout << ans << "\n";
    
    return 0;
}