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
#define N 200010
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
const int Mod = 1e9 + 7;

int n;
int e[N], ne[N], h[N], idx;
int a[N], b[N][32];
int dp[N][32][2];
int sum[N], res[N];
long long ans = 0, rres = 0;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dffs(int x, int fa)
{
    sum[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dffs(j, x);
        sum[x] *= (sum[j] + 1);
    }
}

void dfs(int x, int fa, int id)
{
    if(b[x][id])
        dp[x][id][1] = 1;
    else
        dp[x][id][0] = 1;
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs(j, x, id);
        dp[x][id][0] += dp[j][id][0];
        dp[x][id][1] += dp[j][id][1];
    }
}

void dfs1(int x, int fa, int id)
{
    int op0 = 0, op1 = 0;
    if(b[x][id])
        op1++;
    else
        op0++;
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs1(j, x, id);
        res[x] += dp[j][id][0] * op1 + dp[j][id][1] * op0;
        op1 += dp[j][id][1];
        op0 += dp[j][id][0];
    }
}

void dfs2(int x, int fa, int id)
{
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs2(j, x, id);
        (res[x] += ((dp[j][id][b[x][id] ^ 1] + res[j]) % Mod) * (sum[x] / (sum[j] + 1)) % Mod) %=
            Mod;
        rres += res[x];
    }
}

signed main()
{
    memset(h, -1, sizeof h);

    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 30; j++) {
            b[i][j] = (a[i] >> j) & 1;
        }
    }

    for(int i = 1; i < n; i++) {
        int a, b;
        read(a), read(b);
        add(a, b);
        add(b, a);
    }

    dffs(1, 1);

    // for(int i = 1; i <= n; i++) cout << sum[i] << " ";
    // cout << endl;

    for(long long i = 0, j = 1; i <= 31; i++, j <<= 1) {
        j = j % Mod;
        dfs(1, 1, i);
        // dfs1(1, 1, i);
        dfs2(1, 1, i);
        for(int j = 1; j <= n; j++) cout << res[j] << " ";
        cout << endl;
        cout << rres << endl;
        if(rres & 1) (ans += j) %= Mod;
        rres >>= 1;

        for(int k = 1; k <= n; k++) res[k] = 0;
    }

    cout << ans * 2 << endl;

    return 0;
}
