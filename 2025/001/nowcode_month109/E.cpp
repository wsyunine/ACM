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
int a[N];
int g[N][2];
int f[N];

signed main()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);

    for(int i = 1; i <= n; i++) {
        while(a[i] % 25 == 0) a[i] /= 25;
    }

    if(a[1] % 5ll == 0)
        g[1][1] = a[1], g[1][0] = 0;
    else
        g[1][0] = a[1], g[1][1] = 0;

    for(int i = 2; i <= n; i++) {
        if(a[i] % 5ll) {
            g[i][0] = (g[i - 1][0] * a[i] % Mod + a[i]) % Mod;
            g[i][1] = (g[i - 1][1] * a[i] % Mod);
        }
        else {
            g[i][0] = ((g[i - 1][1] * a[i] / 25LL) % Mod);
            g[i][1] = (g[i - 1][0] * a[i] % Mod + a[i]) % Mod;
        }
        cout << g[i][0] << " " << g[i][1] << endl;
    }

    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] + g[i][0] + g[i][1]) % Mod;
    }

    cout << f[n] << endl;

    return 0;
}
