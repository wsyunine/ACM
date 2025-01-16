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

int n, m;
int e[N], ne[N], idx, h[N];
int d[N], f[N][30];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int x, int fa)
{
    d[x] = d[fa] + 1;
    f[x][0] = fa;
    for(int i = 1; i <= 19; i++) f[x][i] = f[f[x][i - 1]][i - 1];
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs(j, x);
    }
}

int lca(int x, int y)
{
    if(x == y) return x;
    if(d[x] < d[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) {
        if(d[f[x][i]] >= d[y]) x = f[x][i];
    }

    if(x == y) return x;
    // cerr << x << " " << y << endl;
    for(int i = 19; i >= 0; i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }

    // cerr << x << endl;
    return f[x][0];
}

int main()
{
    memset(h, -1, sizeof h);
    read(n), read(m);

    for(int i = 1; i < n; i++) {
        int a, b;
        read(a), read(b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);

    while(m--) {
        int k, mxd = 0, sd;
        vector<int> s;
        read(k);
        for(int i = 1, j; i <= k; i++) {
            read(j), s.push_back(j);
            if(d[j] > mxd) mxd = d[j], sd = j;
        }

        int idea = 1;
        for(int i = 0; i < s.size(); i++) {
            int op = lca(sd, s[i]);
            // cerr << op << endl;
            if(d[s[i]] - d[op] > 1) idea = 0;
        }

        if(idea)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
