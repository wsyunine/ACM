
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
int n, k;
int a[N];
int num[N];

void solve()
{
    read(n), read(k);

    for(int i = 1; i <= 2 * n; i++) num[i] = 0;

    for(int i = 1; i <= n; i++) read(a[i]), num[a[i]]++;

    int res = 0;
    for(int i = 1; i <= k / 2; i++) {
        if(i + i != k)
            res += min(num[i], num[k - i]);
        else
            res += num[i] / 2;
    }

    cout << res << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
