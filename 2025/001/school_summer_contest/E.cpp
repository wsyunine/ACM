#include <bits/stdc++.h>

#include <algorithm>
#include <queue>

using namespace std;

#define N 200010

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

int n;
int m;
int st, ed;
long long dis[2][3010];
int vis[3010];
bool mapp[3010][3010];

void bfs(int x, int id)
{
    queue<int> q;
    for(int i = 1; i <= n; i++) dis[id][i] = 0x3f3f3f3f, vis[i] = 0;
    q.push(x);
    dis[id][x] = 0;
    vis[x] = 1;
    while(q.size()) {
        int t = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(i == t) continue;
            if(!mapp[i][t]) continue;
            if(vis[i]) continue;
            dis[id][i] = dis[id][t] + 1;
            vis[i] = 1;
            q.push(i);
        }
    }
}

signed main()
{
    read(n), read(m);

    read(st), read(ed);

    for(int i = 1; i <= m; i++) {
        int x, y;
        read(x), read(y);
        mapp[x][y] = 1;
        mapp[y][x] = 1;
    }

    bfs(st, 0);
    bfs(ed, 1);

    long long diss = dis[0][ed];
    int res = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(mapp[i][j] || mapp[j][i]) continue;
            if(dis[0][i] + dis[1][j] + 1ll >= diss && dis[0][j] + dis[1][i] + 1ll >= diss) res++;
        }
    }

    printf("%d\n", res);

    return 0;
}
