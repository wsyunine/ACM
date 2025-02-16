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

ll T, n, a[N];

void solve()
{
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1) {
            printf("-1\n");
            return;
        }
    }
    printf("1000000007\n");
}

int main()
{
    read(T);
    while(T--) {
        read(n);
        for(int i = 1; i <= n; i++) read(a[i]);
        solve();
    }

    return 0;
}
