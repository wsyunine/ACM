
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
const int Mod = 998244353;

int T;
int n;
int a[N];

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);

    int op1, op2, s1, s2;
    op1 = a[1];
    s1 = a[1] == 0 ? 1 : 0;
    op2 = 1;
    s2 = 1;
    for(int i = 2; i <= n; i++) {
        int xop1, xop2, xs1 = 0, xs2 = 0;
        xop1 = a[i];
        xop2 = a[i - 1] + 1;
        if(a[i] == op1) (xs1 += s1) %= Mod;
        if(a[i] == op2) (xs1 += s2) %= Mod;
        if(a[i - 1] == op1) (xs2 += s1) %= Mod;

        op1 = xop1;
        s1 = xs1;
        op2 = xop2;
        s2 = xs2;
        // cout << op1 << " " << s1 << " " << op2 << " " << s2 << endl;
    }

    int ans = (s1 + s2) % Mod;
    cout << ans << endl;
}

signed main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
