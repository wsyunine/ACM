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
#define N 600010
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
const int inf = 2147483647;

int n, m;
int x, y, z;
int rt, cnt = 0;
int key[N], val[N], siz[N], ls[N], rs[N];
int tgr[N], tag[N], mx[N];

void pushup(int x)
{
    siz[x] = siz[ls[x]] + siz[rs[x]] + 1;
    mx[x] = max(max(mx[ls[x]], mx[rs[x]]), val[x]);
}

void pushdown(int x)
{
    if(tgr[x]) {
        if(rs[x]) tgr[rs[x]] ^= 1;
        if(ls[x]) tgr[ls[x]] ^= 1;
        ls[x] ^= rs[x] ^= ls[x] ^= rs[x];
        tgr[x] = 0;
    }
    if(tag[x]) {
        if(ls[x]) {
            val[ls[x]] += tag[x];
            mx[ls[x]] += tag[x];
            tag[ls[x]] += tag[x];
        }
        if(rs[x]) {
            val[rs[x]] += tag[x];
            mx[rs[x]] += tag[x];
            tag[rs[x]] += tag[x];
        }
        tag[x] = 0;
    }
}

int build(int x)
{
    val[++cnt] = x;
    siz[cnt] = 1;
    key[cnt] = rand();
    ls[cnt] = 0;
    rs[cnt] = 0;
    tag[cnt] = 0;
    tgr[cnt] = 0;
    mx[cnt] = x;
    return cnt;
}

int cpy(int x)
{
    cnt++;
    val[cnt] = val[x];
    mx[cnt] = mx[x];
    siz[cnt] = siz[x];
    key[cnt] = key[x];
    ls[cnt] = ls[x];
    rs[cnt] = rs[x];
    return cnt;
}

void merge(int &p, int a, int b)
{
    pushdown(a), pushdown(b);
    if(!a || !b) {
        p = a + b;
        return;
    }
    if(key[a] < key[b]) {
        p = a;
        merge(rs[a], rs[a], b);
    }
    else {
        p = b;
        merge(ls[b], a, ls[b]);
    }
    pushup(p);
}

void split_by_value(int p, int k, int &a, int &b)
{
    if(!p) {
        a = b = 0;
        return;
    }
    pushdown(p);
    if(val[p] <= k) {
        a = p;
        split_by_value(rs[a], k, rs[a], b);
        pushup(a);
    }
    else {
        b = p;
        split_by_value(ls[b], k, a, ls[b]);
        pushup(b);
    }
}

void split_by_size(int p, int k, int &a, int &b)
{
    if(!p) {
        a = b = 0;
        return;
    }
    pushdown(p);
    if(siz[ls[p]] < k) {
        a = p;
        split_by_size(rs[p], k - siz[ls[p]] - 1, rs[a], b);
        pushup(p);
    }
    else {
        b = p;
        split_by_size(ls[p], k, a, ls[b]);
        pushup(p);
    }
}

void insert(int &root, int w) { merge(root, root, build(w)); }

void modify(int l, int r, int v)
{
    split_by_size(rt, r, y, z);
    split_by_size(y, l - 1, x, y);
    val[y] += v;
    tag[y] += v;
    mx[y] += v;
    // cerr << siz[y] << endl;
    // cerr << siz[y] << " " << val[x] << " ";

    merge(y, x, y);
    // cerr << val[x] << " ";

    merge(rt, y, z);
    // cerr << siz[rt] << endl;
}

void rev(int l, int r)
{
    split_by_size(rt, r, y, z);
    split_by_size(y, l - 1, x, y);
    tgr[y] ^= 1;
    merge(y, x, y);
    merge(rt, y, z);
}

int query(int l, int r)
{
    split_by_size(rt, r, y, z);
    // cerr << val[y] << " ";
    split_by_size(y, l - 1, x, y);
    int res = mx[y];
    merge(y, x, y);
    merge(rt, y, z);
    return res;
}

int main()
{
    memset(mx, 0xf3, sizeof(mx));
    srand(time(0));

    read(n), read(m);

    rt = 0;
    for(int i = 1; i <= n; i++) insert(rt, 0);
    while(m--) {
        int op, l, r, v;
        read(op);
        read(l), read(r);
        if(op == 1) {
            read(v);
            modify(l, r, v);
        }
        else if(op == 2) {
            rev(l, r);
        }
        else {
            printf("%d\n", query(l, r));
        }
        // for(int i = 1; i <= n; i++) cerr << query(i, i) << " ";
        // cerr << endl;
    }

    return 0;
}
