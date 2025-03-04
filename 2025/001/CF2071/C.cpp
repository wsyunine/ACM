
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

int t;
int n;

int e[N], ne[N], idx, h[N];
int son[N], f[N];
int st, ed;
vector<int> dot;
vector<int> ans;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int x, int fa)
{
    if(x == ed) {
        son[x] = x;
        dot.push_back(x);
        return;
    }
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        dfs(j, x);
        f[j] = x;
        if(son[j] != -1) {
            son[x] = j, dot.push_back(x);
            return;
        }
    }
}

void dfs1(int x, int fa)
{
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == f[x] || j == son[x] || j == fa) continue;
        dfs1(j, x);
    }
    ans.push_back(x);
}

void solve()
{
    idx = 0;
    dot.clear();
    ans.clear();
    read(n);
    read(st), read(ed);
    for(int i = 1; i <= n; i++) h[i] = -1, son[i] = -1, f[i] = 0;

    for(int i = 1; i < n; i++) {
        int a, b;
        read(a), read(b);
        add(a, b);
        add(b, a);
    }

    dfs(st, st);

    reverse(dot.begin(), dot.end());

    for(auto i : dot) {
        dfs1(i, i);
    }

    for(auto i : ans) {
        printf("%d ", i);
    }
    cout << endl;
}

int main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
