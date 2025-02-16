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

int n;
int a[N], s;

signed main()
{
    read(n);
    s = 0;
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        s += a[i];
    }
    if((n + 1) * n / 2 != s) {
        cout << -1 << endl;
        return 0;
    }
    sort(a + 1, a + 1 + n);

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == i) continue;
        res += (i - a[i] > 0 ? i - a[i] : 0);
    }

    cout << res << endl;

    return 0;
}
