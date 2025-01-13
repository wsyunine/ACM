#include <bits/stdc++.h>
// #pragma GCC optimize(3,"Ofast","inline")
// #define int long long
#define i128 __int128
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ld double
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define rep(k, l, r) for(int k = l; k <= r; ++k)
#define per(k, r, l) for(int k = r; k >= l; --k)
#define cl(f, x) memset(f, x, sizeof(f))
#define pcnt(x) __builtin_popcount(x)
#define lg(x) (31 - __builtin_clz(x))
using namespace std;
void file_IO()
{
    //	system("fc .out .ans");
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
}
bool M1;
int read()
{
    int x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch <= '9' && ch >= '0') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}
#define ls(k) (k << 1)
#define rs(k) (k << 1 | 1)
#define pa(k) (k >> 1)
#define sonid(k) (rs(pa(k)) == k)
#define bro(k) (k ^ 1)
const int N = 5e5 + 5, M = 20;
char s[M][N];
int f[N], g[N], p[M], pos[N], ta[N], opp[N], c[N], t[N], n, m, l, k;
void dfs(int x, int d)
{
    ++p[d];
    if(d == k) {
        pos[p[d]] = x;
        t[x] = p[d];
        return;
    }
    opp[x] = s[d][p[d]] - 48;
    dfs(ls(x), d + 1);
    dfs(rs(x), d + 1);
}
void init()
{
    n = read();
    m = read();
    rep(i, 1, n) ta[i] = read();
    rep(i, 1, m) c[i] = read();
    l = 1;
    k = 0;
    while(l < n) l <<= 1, ++k;
    per(i, k - 1, 0) scanf("%s", s[i] + 1);
    dfs(1, 0);
}
int tc[4], a[N];
void dfs1(int x, int d)
{
    if(d == k) {
        f[x] = t[x];
        g[x] = t[x] - 1;
        return;
    }
    dfs1(ls(x), d + 1);
    dfs1(rs(x), d + 1);
    if(!opp[x]) {
        if(a[f[ls(x)]] >= k - d) {
            f[x] = f[ls(x)];
            g[x] = g[ls(x)];
        }
        else {
            f[x] = f[rs(x)];
            g[x] = g[rs(x)];
        }
        chkmax(g[x], g[ls(x)]);
    }
    else {
        if(a[f[rs(x)]] >= k - d) {
            f[x] = f[rs(x)];
            g[x] = g[rs(x)];
        }
        else {
            f[x] = f[ls(x)];
            g[x] = g[ls(x)];
        }
        chkmax(g[x], g[rs(x)]);
    }
}
ll ans[N];
void upd(int _l, int _r, int val)
{
    chkmin(_r, l);
    if(_l > _r) return;
    ans[_l] += val;
    ans[_r + 1] -= val;
}
void dfs2(int x, int d, int _l, int _r, int val, int mx)
{
    if(_l > val) return;
    if(d == k) {
        int p = t[x];
        if(a[p] >= mx) upd(max(_l, p), min(_r, val), p);
        upd(_l, min(p - 1, val), p);
        return;
    }
    if(!opp[x]) {
        dfs2(ls(x), d + 1, _l, _r, val, max(k - d, mx));
        dfs2(rs(x), d + 1, _l, _r, a[f[ls(x)]] >= k - d ? min(val, g[ls(x)]) : val, mx);
    }
    else {
        dfs2(ls(x), d + 1, _l, _r, a[f[rs(x)]] >= k - d ? min(val, g[rs(x)]) : val, mx);
        dfs2(rs(x), d + 1, _l, _r, val, max(k - d, mx));
    }
}
void solve()
{
    rep(i, 0, 3) tc[i] = read();
    rep(i, 1, n) a[i] = ta[i] ^ tc[i % 4];
    rep(i, n + 1, l) a[i] = INF;
    dfs1(1, 0);
    rep(i, 0, n) ans[i] = 0;
    upd(1, 1, 1);
    int rt = 1, d = 0;
    while(ls(rt) <= l) {
        dfs2(rt, d, (1 << (k - d - 1)) + 1, 1 << (k - d), INF, 0);
        rt = ls(rt);
        ++d;
    }
    rep(i, 1, n) ans[i] += ans[i - 1];
    ll res = 0;
    for(int i = 1; i <= n; i++) cerr << ans[i] << endl;
    rep(i, 1, m) res ^= i * ans[c[i]];
    printf("%lld\n", res);
}
bool M2;
signed main()
{
    //	file_IO();
    init();
    int testcase = read();
    while(testcase--) solve();
    return 0;
}
