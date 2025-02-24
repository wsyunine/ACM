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

__int128 n, m;
int t;

__int128 abss(__int128 x)
{
    if(x < 0)
        return -x;
    else
        return x;
}

signed main()
{
    read(t);
    while(t--) {
        read(n), read(m);

        if(m == 1) {
            cout << 1 << endl;
            continue;
        }

        int sum = 1;
        __int128 opt = m;
        while(abss(m * opt - n) < abss(opt - n)) {
            opt = m * opt;
            sum++;
        }

        cout << sum << endl;
    }

    return 0;
}
