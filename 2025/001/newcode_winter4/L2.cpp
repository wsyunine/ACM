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
#define ll long long
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
const ll Mod = 1e9 + 7;

int n, q;
int t;
int a[N];
int b[N];
int sum0[N][32], sum1[N][32];
int s0[N][32], s1[N][32];
ll res0[N][32], res1[N][32];

void solve()
{
    read(n);
    read(q);
    for(int i = 1; i <= n; i++) read(a[i]);
    for(int i = 1; i <= n; i++) read(b[i]);

    for(int i = 0; i <= 30; i++) {
        for(int j = 1; j <= n; j++) {
            sum0[j][i] = sum0[j - 1][i] + (((b[j] >> i) & 1) == 0);
            sum1[j][i] = sum1[j - 1][i] + (((b[j] >> i) & 1) == 1);
            s0[j][i] = s0[j - 1][i] + (((a[j] >> i) & 1) == 0);
            s1[j][i] = s1[j - 1][i] + (((a[j] >> i) & 1) == 1);
        }
        ll op0 = 0, op1 = 0;
        for(int j = 1; j <= n; j++) {
            ll opb = (b[j] >> i) & 1;
            if(((a[j] >> i) & 1) == 1) {
                res0[j][i] = (res0[j - 1][i] + (opb == 0) * op1 + (opb == 0)) % Mod;
                res1[j][i] = (res1[j - 1][i] + (opb == 1) * op0) % Mod;
                op1++;
            }
            else {
                res1[j][i] = (res1[j - 1][i] + (opb == 1) * op0 + (opb == 1)) % Mod;
                res0[j][i] = (res0[j - 1][i] + (opb == 0) * op1) % Mod;
                op0++;
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << sum0[i][0] << " " << sum1[i][0] << " " << s0[i][0] << " " << s1[i][0] << " "
    //          << res0[i][0] << " " << res1[i][0] << endl;
    // }

    while(q--) {
        int l, r;
        read(l), read(r);

        ll up = 1, ans = 0;
        for(int i = 0; i <= 30; i++, up = up * 2ll % Mod) {
            ll x = (res0[r][i] - res0[l - 1][i] -
                    (ll)(sum0[r][i] - sum0[l - 1][i]) * (ll)s1[l - 1][i] % Mod) %
                       Mod +
                   Mod;
            ll y = (res1[r][i] - res1[l - 1][i] -
                    (ll)(sum1[r][i] - sum1[l - 1][i]) * (ll)s0[l - 1][i] % Mod) %
                       Mod +
                   Mod;
            (ans += up * (x + y) % Mod) %= Mod;
        }

        printf("%lld\n", ans);
    }
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
