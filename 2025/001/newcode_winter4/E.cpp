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
#include <unordered_map>
#include <vector>
using namespace std;
#define N 500010
#define ll long long
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
int n, m;
ll mapp[1010][1010];
unordered_map<int, ll> mapp1, mapp2;
ll res = 0;

void solve()
{
    mapp1.clear();
    mapp2.clear();
    res = 0;
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            read(mapp[i][j]);
        }
    }

    for(int i = n - 1; i >= 1 - m; i--) {
        for(int j = 1; j <= n; j++) {
            int k = j - i;
            if(k <= 0) continue;
            if(k > m) continue;
            mapp1[i] += mapp[j][k];
        }
    }

    for(int i = 2; i <= n + m; i++) {
        for(int j = 1; j <= n; j++) {
            int k = i - j;
            if(k <= 0) continue;
            if(k > m) continue;
            mapp2[i] += mapp[j][k];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            res = max(mapp1[i - j] + mapp2[i + j] - mapp[i][j], res);
        }
    }

    cout << res << endl;
}

int main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
