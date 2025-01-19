
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

int T;
int n, m1, m2;
int f[N];
int ans = 0;
pair<int, int> p[N], q[N];
int vis[N];

int find(int x)
{
    if(x == f[x]) return x;
    return (f[x] = find(f[x]));
}

void solve()
{
    read(n);
    ans = 0;
    read(m1), read(m2);

    for(int i = 1; i <= n; i++) f[i] = i;

    for(int i = 1; i <= m1; i++) {
        int x, y;
        read(x), read(y);
        if(x > y) swap(x, y);
        p[i] = {x, y};
        vis[i] = 1;
    }

    for(int i = 1; i <= m2; i++) {
        int x, y;
        read(x), read(y);
        if(x > y) swap(x, y);
        q[i] = {x, y};
        int xx = find(x), yy = find(y);
        if(xx != yy) {
            f[yy] = xx;
        }
    }

    for(int i = 1; i <= m1; i++) {
        if(find(p[i].first) != find(p[i].second)) vis[i] = 0, ans++;
    }

    for(int i = 1; i <= n; i++) f[i] = i;

    for(int i = 1; i <= m1; i++) {
        if(vis[i]) {
            int x = find(p[i].first), y = find(p[i].second);
            if(x != y) {
                f[x] = y;
            }
        }
    }

    for(int i = 1; i <= m2; i++) {
        int x = find(q[i].first), y = find(q[i].second);
        if(x != y) ans++, f[x] = y;
    }

    cout << ans << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
