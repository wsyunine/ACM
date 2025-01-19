
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
int n, m;
int cow[N];
int ans[N];
int vis[N];

void solve()
{
    int idea = 1;
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
        for(int j = 1; j <= m; j++) {
            int x;
            read(x);
            cow[x] = i;
        }
    }

    for(int i = 0; i < n; i++) {
        ans[i] = cow[i];
        if(vis[cow[i]]) {
            idea = 0;
            break;
        }
        vis[cow[i]] = 1;
    }

    for(int i = n; i <= n * m - 1; i++) {
        if(cow[i] != cow[i % n]) {
            idea = 0;
            break;
        }
    }

    if(idea) {
        for(int i = 0; i < n; i++) printf("%d ", ans[i]);
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
