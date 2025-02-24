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
int mapp[510][510];
int vis[510][510];
int res = 0;
int ans = 0x3f3f3f3f;
vector<pair<int, int>> v;

void dfs(int x, int y)
{
    if(x == 0 || y == 0 || x > n || y > m) return;
    if(vis[x][y]) return;
    vis[x][y] = 1;
    if(x != 1 && mapp[x - 1][y] == 0)
        v.push_back({x - 1, y}), mapp[x - 1][y] = 2, res++;
    else if(mapp[x - 1][y] == 1)
        dfs(x - 1, y);
    if(y != 1 && mapp[x][y - 1] == 0)
        v.push_back({x, y - 1}), mapp[x][y - 1] = 2, res++;
    else if(mapp[x][y - 1] == 1)
        dfs(x, y - 1);
    if(x != n && mapp[x + 1][y] == 0)
        v.push_back({x + 1, y}), mapp[x + 1][y] = 2, res++;
    else if(mapp[x + 1][y] == 1)
        dfs(x + 1, y);
    if(y != m && mapp[x][y + 1] == 0)
        v.push_back({x, y + 1}), mapp[x][y + 1] = 2, res++;
    else if(mapp[x][y + 1] == 1)
        dfs(x, y + 1);
}

int main()
{
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            vis[i][j + 1] = 0;
            mapp[i][j + 1] = (str[j] == '0') ? 0 : 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!vis[i][j] && mapp[i][j] == 1) {
                v.clear();
                res = 0;
                dfs(i, j);
                ans = min(ans, res);
                for(auto i : v) mapp[i.first][i.second] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
