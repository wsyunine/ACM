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
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define N 300010
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

int T;
int n;
int a[N], lst[N];
size_t tmp[1000001];
long long dp[N], s[N];

void solve()
{
    read(n);
    a[0] = 0;
    dp[0] = 0;
    s[0] = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++) read(a[i]), dp[i] = 0, mx = max(mx, a[i]);
    for(int i = 1; i <= mx; i++) tmp[i] = -1;
    for(int i = 1; i <= n; i++) {
        lst[i] = tmp[a[i]];
        tmp[a[i]] = i;
        if(a[i] == a[i - 1]) {
            s[i] = s[i - 1] + (long long)a[i];
        }
        else
            s[i] = s[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if(lst[i] != -1) {
            dp[i] = max(dp[i], dp[lst[i] + 1] + (long long)a[i] + s[i] - s[lst[i] + 1]);
        }
    }

    printf("%lld\n", dp[n]);
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}

