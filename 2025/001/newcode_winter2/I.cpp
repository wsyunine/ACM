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

void dfs(int x, int fa, int id)
{
    dp[x][id][b[x][id]] = 1;
    dp[x][id][b[x][id] ^ 1] = 0;
    sum[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs(j, x, id);
        (res[x] += (res[j] * sum[x] % Mod + res[x] * sum[j] % Mod) % Mod) %= Mod;
        (res[x] += (dp[x][id][0] * dp[j][id][1] % Mod + dp[j][id][0] * dp[x][id][1] % Mod) % Mod) %=
            Mod;
        (dp[x][id][0] += (dp[j][id][0] * sum[x] % Mod + dp[x][id][0] * sum[j] % Mod) % Mod) %= Mod;
        (dp[x][id][1] += (dp[j][id][1] * sum[x] % Mod + dp[x][id][1] * sum[j] % Mod) % Mod) %= Mod;
        (sum[x] += sum[x] * sum[j] % Mod) %= Mod;
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

    // for(int i = 1; i <= n; i++) cout << sum[i] << " ";
    // cout << endl;

    for(long long i = 0, j = 1; i <= 30; i++, j <<= 1ll) {
        j = j % Mod;
        dfs(1, 1, i);
        for(int k = 1; k <= n; k++) (rres += res[k]) %= Mod;
        (ans += rres * j % Mod) %= Mod;
        rres = 0;

        for(int k = 1; k <= n; k++) res[k] = 0;
    }

    cout << ans * 2ll % Mod << endl;

    return 0;
}
