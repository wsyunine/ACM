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
int n;
int a[N], b[N], dp[N];
unordered_map<int, int> mapp[2];
int t[N];

void add(int x, int y)
{
    for(; x <= n; x += x & (-x)) t[x] += y;
}

int query(int x)
{
    int res = 0;
    for(; x; x -= x & (-x)) res += t[x];
    return res;
}

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    long long res = 0;

    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[j] < i)
                b[j] = 1;
            else if(a[j] > i)
                b[j] = -1;
            else
                b[j] = 1;
        }

        for(int j = 1; j <= 2 * n + 10; j++) t[j] = 0;
        for(int j = 1; j <= n; j++) cerr << b[j] << " ";
        cerr << endl;

        int tmp = 0;
        add(n + 1, 1);
        for(int j = 1; j <= n; j++) {
            tmp += b[j];
            res += query(tmp + n);
            add(tmp + n + 1, 1);
        }

        cerr << res << endl;
    }
    printf("%lld\n", res);
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
