#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

int n, k, p;
int a[1000005];

bool check(int x)
{
    /// 檢查 有 p 隊伍，每個隊伍 k 個人，身高差 <= x
    if (k == 2) {
        int cnt = 0;
        for (int i = 1; i <= n - 1; i++) {
            if (a[i + 1] - a[i] <= x) {
                cnt++;
                i++;
            }
            if (cnt >= p)
                return true;
        }
        return false;
    } else {
        int cnt = 0, pre = -1, pre_pre = -1, first_id = -1;
        for (int i = 1; i <= n; i++) {
            if (pre == -1) {
                pre = a[i];
                first_id = i;
            } else if (pre_pre == -1) {
                pre_pre = pre;
                pre = a[i];
            } else {
                if (a[i] - pre_pre > x) {
                    first_id = i - 1;
                    pre_pre = pre;
                    pre = a[i];
                } else if (i - first_id + 1 == k) {
                    cnt++;
                    pre = pre_pre = first_id = -1;
                } else {
                    pre_pre = pre;
                    pre = a[i];
                }
            }
            if (cnt >= p)
                return true;
        }
        return false;
    }
}

signed main()
{
    IOS

    cin >> n >> k >> p;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int l = -1, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << "\n";
    
    return 0;
}