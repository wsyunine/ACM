
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
const int Mod = 998244353;

int t;
int n;
int p[N];
int e[N], ne[N], idx, h[N];
int d[N], nd[N], v[N], num[N];

bool cmp(int x, int y) { return d[x] < d[y]; }

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int x, int fa)
{
    d[x] = d[fa] + 1;
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs(j, x);
    }
}

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) h[i] = -1, nd[i] = 0, d[i] = 0, num[i] = i;
    for(int i = 2; i <= n; i++) {
        read(p[i]);
        add(i, p[i]);
        add(p[i], i);
    }

    dfs(1, 1);

    sort(num + 1, num + 1 + n, cmp);

    for(int i = 1; i <= n; i++) {
        int j = num[i];
        if(j == 1)
            v[j] = 1;
        else if(p[j] == 1)
            v[j] = 1;
        else
            v[j] = ((nd[d[j] - 1] - v[p[j]]) % Mod + Mod) % Mod;
        (nd[d[j]] += v[j]) %= Mod;
    }

    int res = 0;
    for(int i = 1; i <= n; i++) (res += v[i]) %= Mod;
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
