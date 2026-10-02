#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e18;

const int N = 9, M = 10;
int mat[N][M];
int ans[N];
int A[N][M] = {
    1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 1, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 1, 0, 0, 0, 0,
    1, 0, 0, 1, 1, 0, 1, 0, 0, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    0, 0, 1, 0, 1, 1, 0, 0, 1, 0,
    0, 0, 0, 1, 0, 0, 1, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 1, 1, 0};

void output(int t) {
    cout << t << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            mat[i][j] = A[i][j];
}

void swap_row(int x1, int x2) {
    for (int i = 0; i < M; i++)
        swap(mat[x1][i], mat[x2][i]);
}

bool Gaussian_Elimination() {
    bool check = true;
    int idx;
    for (int i = 0; i < N; i++) {
        /// swap row
        if (mat[i][i] == 0) {
            idx = -1;
            for (int j = i + 1; j < N; j++) {
                if (mat[j][i] != 0) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                cout << "NO ANSWER\n";
                check = false;
                break;
            }
            swap_row(i, idx);
        }

        for (int j = i + 1; j < N; j++) {
            if (mat[j][i] != 0) {
                if (abs(mat[j][i]) >= abs(mat[i][i])) {
                    int mul = mat[j][i] / mat[i][i];
                    for (int k = i; k < M; k++) {
                        mat[j][k] = mat[j][k] - (mat[i][k] * mul);
                    }
                } else {
                    int mul = mat[i][i] / mat[j][i];
                    for (int k = i; k < M; k++) {
                        mat[j][k] = (mat[j][k] * mul) - mat[i][k];
                    }
                }
            }
        }
    }

    /// 同餘
    for (int i = 0; i < N; i++) {
        for (int j = i; j < M; j++) {
            mat[i][j] = (mat[i][j] % 4 + 4) % 4;
        }
    }

    /// 求解
    for (int i = N - 1; i >= 0; i--) {
        for (int k = 0; k < 4; k++) {
            if ((k * mat[i][i]) % 4 == mat[i][M - 1])
                ans[i] = k;
        }

        for (int j = 0; j < i; j++) {
            mat[j][M - 1] -= mat[j][i] * ans[i];
            mat[j][M - 1] = (mat[j][M - 1] % 4 + 4) % 4;
            mat[j][i] = 0;
        }
    }

    return check;
}

void solve() {
    init();

    int x;
    for (int i = 0; i < 9; i++) {
        cin >> x;
        mat[i][M - 1] = 4 - x;
    }

    bool F = Gaussian_Elimination();

    for (int i = 0; i < N; i++)
        for (int t = 1; t <= ans[i]; t++)
            cout << i + 1 << " ";
    cout << "\n";
    /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    */
}

signed main() {
    IO;
    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}