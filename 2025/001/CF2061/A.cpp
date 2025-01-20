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
int n;
int a[N], s0 = 0, s1 = 0;

void solve()
{
    read(n);
    s0 = 0, s1 = 0;
    for(int i = 1; i <= n; i++) read(a[i]), (a[i] & 1) ? s1++ : s0++;

    if(s0) {
        cout << 1 + s1 << endl;
    }
    else {
        cout << s1 - 1 << endl;
    }
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
