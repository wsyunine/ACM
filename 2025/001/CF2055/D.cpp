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
int n, a[N], k, l;

void solve()
{
    read(n), read(k), read(l);
    k *= 2;
    l *= 2;

    for(int i = 1; i <= n; i++) read(a[i]), a[i] *= 2;

    int x = k, ans = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] > x) {
            a[i] = max(x, a[i] - ans);
            ans += (a[i] - x) / 2;
            x = (x + a[i]) / 2 + k;
        }
        else {
            a[i] = min(x, a[i] + ans);
            x = a[i] + k;
        }
    }

    if(x < l) {
        ans += (l - x);
    }

    printf("%d\n", ans);
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
