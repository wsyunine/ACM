

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

int t;
int n;
int a[N];
int l, r;
int pre[N];

void solve()
{
    read(n);
    read(l), read(r);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
    }
    if((n & 1) == 0) {
        n++;
        a[n] = 0;
        for(int i = 1; i <= n / 2; i++) {
            a[n] = a[n] ^ a[i];
        }
    }

    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i];

    if(l <= n) {
        cout << a[l] << endl;
        return;
    }

    l /= 2ll;
    int res = 0;
    while(l > n) {
        if(l & 1ll) {
            res ^= pre[n];
            break;
        }
        else
            res ^= pre[n];
        l /= 2ll;
    }
    if(l <= n) res ^= pre[l];

    cout << res << endl;
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
