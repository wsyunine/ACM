

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
int a[N], l, r, pre[N], xorpre[N];

int getone(int x)
{
    // cerr << "!" << x << endl;
    if(x <= n) {
        return a[x];
    }
    x /= 2ll;
    int res = 0;
    while(x > n) {
        if(x & 1ll) {
            res ^= xorpre[n];
            break;
        }
        else
            res ^= xorpre[n];
        x /= 2ll;
    }
    if(x <= n) res ^= xorpre[x];
    return res;
}

int get(int x)
{
    // cerr << x << endl;
    if(x <= 0) return 0;
    if(x <= 2 * n) return pre[x];
    int res;
    if(x & 1) {
        res = pre[2 * n - 1];
        while(x % 4 != 1) x += 2, res -= getone(x);
        if(xorpre[n])
            res += (x / 2 - n + 1) - (get(x / 2) - pre[n - 1]);
        else
            res += get(x / 2) - pre[n - 1];
    }
    else {
        res = pre[2 * n - 2];
        while(x % 4 != 0) x += 2, res -= getone(x);
        if(xorpre[n])
            res += (x / 2 - n + 1) - (get(x / 2) - pre[n - 1]);
        else
            res += get(x / 2) - pre[n - 1];
    }
    return res;
}

void solve()
{
    read(n), read(l), read(r);
    for(int i = 1; i <= n; i++) read(a[i]);

    if((n & 1) == 0) {
        n++;
        a[n] = 0;
        for(int i = 1; i <= n / 2; i++) {
            a[n] = a[n] ^ a[i];
        }
    }

    for(int i = 1; i <= n; i++) xorpre[i] = xorpre[i - 1] ^ a[i];

    pre[1] = a[1];
    for(int i = 2; i <= 2 * n; i++) {
        if(i <= n)
            pre[i] = pre[i - 2] + a[i];
        else
            pre[i] = pre[i - 2] + xorpre[i / 2];
    }

    int op1 = get(r) + get(r - 1);
    int op2 = get(l - 1) + get(l - 2);

    // cerr << get(7) << endl;

    // for(int i = l; i <= r; i++) cerr << get(i) << endl;
    cout << op1 - op2 << endl;
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
