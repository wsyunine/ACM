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

struct node {
    long long a, b, v;
} s[N];

bool cmp(node a, node b) { return a.a < b.a; }

int n, m;
long long dp[N];
long long vs[N];

int main()
{
    memset(dp, 0x3f, sizeof dp);
    read(n), read(m);
    for(int i = 1; i <= n; i++) read(s[i].a);
    for(int i = 1; i <= n; i++) read(s[i].b), read(s[i].v);

    sort(s + 1, s + 1 + n, cmp);

    for(int i = 1; i <= n; i++) vs[i] = vs[i - 1] + s[i].v;

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + s[i].v;
        int l = 1, r = i - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(s[mid].a >= s[i].a - m + 1)
                r = mid - 1;
            else
                l = mid;
        }
        // cout << l << " ";
        if(s[l].a >= s[i].a - m + 1) {
            dp[i] = min(dp[i], s[i].b + vs[i - 1]);
        }
        else {
            dp[i] = min(dp[i], s[i].b + dp[l] + vs[i - 1] - vs[l]);
        }
        // cout << dp[i] << endl;
    }

    cout << dp[n] << endl;

    return 0;
}
