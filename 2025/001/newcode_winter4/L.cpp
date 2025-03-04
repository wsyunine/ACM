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
#define N 800010
#define ll long long
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
const ll Mod = 1e9 + 7;

struct node {
    short a0, a1, b0, b1;
    int res0, res1;
} t[N][21];

int T;
int n, q;
int a[N], b[N];

void pushup(int x, int id)
{
    t[x][id].a0 = t[x << 1][id].a0 + t[x << 1 | 1][id].a0;
    t[x][id].a1 = t[x << 1][id].a1 + t[x << 1 | 1][id].a1;
    t[x][id].b0 = t[x << 1][id].b0 + t[x << 1 | 1][id].b0;
    t[x][id].b1 = t[x << 1][id].b1 + t[x << 1 | 1][id].b1;
    t[x][id].res0 = (((ll)t[x << 1 | 1][id].b0 * (ll)t[x << 1][id].a1) % Mod +
                     (ll)t[x << 1 | 1][id].res0 + (ll)t[x << 1][id].res0) %
                    Mod;
    t[x][id].res1 = (((ll)t[x << 1 | 1][id].b1 * (ll)t[x << 1][id].a0 % Mod) +
                     (ll)t[x << 1 | 1][id].res1 + (ll)t[x << 1][id].res1) %
                    Mod;
}

void build(int x, int l, int r, int id)
{
    if(l == r) {
        int op1 = (a[l] >> id) & 1;
        int op2 = (b[l] >> id) & 1;
        t[x][id].a0 = (op1 == 0);
        t[x][id].a1 = (op1 == 1);
        t[x][id].b0 = (op2 == 0);
        t[x][id].b1 = (op2 == 1);
        if(op1) {
            t[x][id].res0 = t[x][id].b0;
            t[x][id].res1 = 0;
        }
        else {
            t[x][id].res0 = 0;
            t[x][id].res1 = t[x][id].b1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid, id);
    build(x << 1 | 1, mid + 1, r, id);
    pushup(x, id);
}

node query(int x, int l, int r, int ql, int qr, int id)
{
    if(ql <= l && qr >= r) {
        return t[x][id];
    }
    int mid = (l + r) >> 1;
    if(qr <= mid) {
        return query(x << 1, l, mid, ql, qr, id);
    }
    else if(ql > mid) {
        return query(x << 1 | 1, mid + 1, r, ql, qr, id);
    }
    else {
        node opt1, opt2, opt;
        opt1 = query(x << 1, l, mid, ql, qr, id);
        opt2 = query(x << 1 | 1, mid + 1, r, ql, qr, id);
        opt.a0 = opt1.a0 + opt2.a0;
        opt.a1 = opt1.a1 + opt2.a1;
        opt.b0 = opt1.b0 + opt2.b0;
        opt.b1 = opt1.b1 + opt2.b1;
        opt.res0 = (((ll)opt2.b0 * (ll)opt1.a1) % Mod + (ll)opt2.res0 + (ll)opt1.res0) % Mod;
        opt.res1 = (((ll)opt2.b1 * (ll)opt1.a0 % Mod) + (ll)opt2.res1 + (ll)opt1.res1) % Mod;
        return opt;
    }
}

void solve()
{
    read(n), read(q);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
    }
    for(int i = 1; i <= n; i++) read(b[i]);

    for(int i = 0; i <= 20; i++) build(1, 1, n, i);

    while(q--) {
        ll ans = 0, up = 1;
        int l, r;
        read(l), read(r);
        for(int i = 0; i <= 20; i++, up = up * 2ll % Mod) {
            node res = query(1, 1, n, l, r, i);
            (ans += up * (res.res0 + res.res1) % Mod) %= Mod;
        }
        printf("%lld\n", ans);
    }
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
