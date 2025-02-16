
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
#define N 500010
#define ll long long
#define int long long
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
ll a[N], b[N];
vector<ll> d;
ll res;
ll pre[N], suf[N];

void solve()
{
    read(n);
    res = 0;
    for(int i = 0; i <= n + 10; i++) pre[i] = suf[i] = 0;
    for(int i = 1; i <= n; i++) read(a[i]);

    for(int i = 1; i <= n; i++) {
        if(a[i] > 0)
            pre[i] = pre[i - 1] + a[i];
        else
            pre[i] = pre[i - 1];
    }
    for(int i = n; i >= 1; i--) {
        if(a[i] < 0)
            suf[i] = suf[i + 1] - a[i];
        else
            suf[i] = suf[i + 1];
    }

    for(int i = 1; i <= n; i++) {
        res = max(res, pre[i - 1] + suf[i]);
    }
    res = max(res, pre[n]);

    cout << res << endl;
}

signed main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
