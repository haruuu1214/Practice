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

int a[100005];
int ans = 0;

void merge(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    merge(l, mid); merge(mid + 1, r);

    vector <int> tmp;
    int cntl = 0;
    int pl = l, pr = mid + 1;
    while (pl <= mid && pr <= r) {
        if (a[pl] > a[pr]) {
            tmp.push_back(a[pl]);
            cntl++;
            pl++;
        } else {
            tmp.push_back(a[pr]);
            ans += cntl;
            pr++;
        }
    }
    while (pl <= mid) {
        tmp.push_back(a[pl]);
        pl++;
    }
    while (pr <= r) {
        tmp.push_back(a[pr]);
        ans += cntl;
        pr++;
    }
    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];
}

signed main()
{
    IOS
    
    int n;
    int t = 0;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ans = 0;
        merge(1, n);
        cout << "Case #" << ++t << ": " << ans << "\n";
    }
    
    return 0;
}