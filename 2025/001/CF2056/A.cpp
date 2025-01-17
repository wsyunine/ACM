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
int n, m;
int a[N], b[N];

void solve()
{
    read(m), read(n);
    int x = 0, y = 0;
    for(int i = 1; i <= m; i++) {
        read(a[i]), read(b[i]);
        x += a[i], y += b[i];
    }
    x += n, y += n;
    cout << x - a[1] + x - a[1] + y - b[1] + y - b[1] << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
