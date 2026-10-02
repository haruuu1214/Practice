#include <bits/stdc++.h>
#include "lib1044.h"
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int N = 100005;

signed main() {
    IO
    
    int n;
    n = Initialize();

    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (Guess(mid))
            r = mid;
        else
            l = mid;
    }
    Report(r);
}