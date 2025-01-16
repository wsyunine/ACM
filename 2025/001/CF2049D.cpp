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
long long a[210][410];
long long k;
long long f[201][201], g[201][201][201];

int main()
{
    memset(f, 0x3f, sizeof(f));
    memset(g, 0x3f, sizeof g);
    read(T);
    while(T--) {
        read(n), read(m), read(k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) read(a[i][j]), f[i][j] = 0x3f3f3f3f3f3f3f3f;
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int p = 0; p < m; p++) g[i][j][p] = 0x3f3f3f3f3f3f3f3f;

        f[0][1] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int p = 0; p < m; p++) {
                    g[i][j][p] =
                        min(f[i - 1][j] + k * p, g[i][j - 1][p]) + a[i][(j + p - 1) % m + 1];
                    f[i][j] = min(f[i][j], g[i][j][p]);
                }
            }
        }

        cout << f[n][m] << endl;
    }

    return 0;
}
