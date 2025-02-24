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

int n, q;
int a[N], b[N], s[N];
int t[N];

void pushup(int x) { t[x] = max(t[x << 1], t[x << 1 | 1]); }

void build(int x, int l, int r)
{
    if(l == r) return t[x] = b[l], void();
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    pushup(x);
}

int query(int x, int l, int r, int ql, int qr)
{
    if(ql <= l && qr >= r) return t[x];
    int mid = (l + r) >> 1, res = -0x3f3f3f3f3f3f3f;
    if(ql <= mid) res = max(res, query(x << 1, l, mid, ql, qr));
    if(qr > mid) res = max(res, query(x << 1 | 1, mid + 1, r, ql, qr));
    return res;
}

signed main()
{
    read(n), read(q);
    for(int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];

    for(int i = 1; i < n; i++) b[i] = a[i + 1] - s[i];

    build(1, 1, n);

    while(q--) {
        int l, r;
        read(l), read(r);
        if(l == r) {
            printf("0\n");
            continue;
        }
        int opt = query(1, 1, n, l, r - 1);
        printf("%lld\n", max(0ll, opt + s[l - 1]));
    }

    return 0;
}
