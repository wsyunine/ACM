
#include <bits/stdc++.h>

using namespace std;

#define N 2500010

template <typename T>
inline void read(T &x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

struct node {
    int a, b, c, d;
};

int n;
int m;
int a[N];
int tl[N], tr[N], t[N], s[N];

void pushup(int x)
{
    t[x] = max(t[x << 1], t[x << 1 | 1]);
    tl[x] = max(tl[x << 1], s[x << 1] + tl[x << 1 | 1]);
    tr[x] = max(tr[x << 1 | 1], s[x << 1 | 1] + tr[x << 1]);
    s[x] = s[x << 1] + s[x << 1 | 1];
    t[x] = max(t[x], tr[x << 1] + tl[x << 1 | 1]);
}

void build(int x, int l, int r)
{
    if(l == r) {
        t[x] = a[l];
        s[x] = a[l];
        tl[x] = a[l];
        tr[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    pushup(x);
}

void modify(int x, int l, int r, int p, int v)
{
    if(l == r) {
        t[x] = v;
        s[x] = v;
        tl[x] = v;
        tr[x] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid)
        modify(x << 1, l, mid, p, v);
    else
        modify(x << 1 | 1, mid + 1, r, p, v);
    pushup(x);
}

node query(int x, int l, int r, int ql, int qr)
{
    if(ql <= l && qr >= r) {
        return node{s[x], t[x], tl[x], tr[x]};
    }
    int mid = (l + r) >> 1;
    if(qr <= mid) {
        return query(x << 1, l, mid, ql, qr);
    }
    else if(ql > mid) {
        return query(x << 1 | 1, mid + 1, r, ql, qr);
    }
    else {
        node xx = query(x << 1, l, mid, ql, qr);
        node y = query(x << 1 | 1, mid + 1, r, ql, qr);
        node z;
        z.a = xx.a + y.a;
        z.b = max(xx.b, y.b);
        z.b = max(z.b, xx.d + y.c);
        z.c = max(xx.c, xx.a + y.c);
        z.d = max(y.d, y.a + xx.d);
        return z;
    }
}

signed main()
{
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
    }
    build(1, 1, n);

    while(m--) {
        int opt;
        int x, y;
        read(opt), read(x), read(y);
        if(opt == 1) {
            if(x > y) swap(x, y);
            printf("%d\n", query(1, 1, n, x, y).b);
        }
        else {
            modify(1, 1, n, x, y);
        }
    }

    return 0;
}
