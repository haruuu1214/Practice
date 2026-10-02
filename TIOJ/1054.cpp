#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int mod = 998244353;
const int INF = 2e9;


const int N = 100005;

map <string, int> mp;
map <int, string> mp2;

signed main()
{
    IO
    
    mp["Monday"] = 0;
    mp["Tuesday"] = 1;
    mp["Wednesday"] = 2;
    mp["Thursday"] = 3;
    mp["Friday"] = 4;
    mp["Saturday"] = 5;
    mp["Sunday"] = 6;

    mp2[0] = "Monday";
    mp2[1] = "Tuesday";
    mp2[2] = "Wednesday";
    mp2[3] = "Thursday";
    mp2[4] = "Friday";
    mp2[5] = "Saturday";
    mp2[6] = "Sunday";

    string s;
    int n;
    cin >> s >> n;
    
    int x = mp[s];
    
    x = (x + n) % 7;
    cout << mp2[x] << "\n";
    
    return 0;
}