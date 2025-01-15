#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <thread>
#include <vector>
using namespace std;
#define int long long
#define N 500010
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n;
int a[N], b[N];
int sa = 0, sb = 0;

void solve()
{
    read(n);
    sa = sb = 0;
    for(int i = 1; i <= n; i++) read(a[i]), sa += a[i];
    for(int i = 1; i <= n; i++) read(b[i]), sb += b[i];

    int tmp = 0, mn = 0x3f3f3f3f, s = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] < b[i]) {
            tmp += (b[i] - a[i]);
            s++;
        }
        else {
            mn = min(mn, a[i] - b[i]);
        }
    }

    if(s > 1) {
        cout << "No" << endl;
    }
    else if(sa < sb + (n - 1) * tmp - tmp) {
        cout << "No" << endl;
    }
    else if(mn < tmp) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}

signed main(void)
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
