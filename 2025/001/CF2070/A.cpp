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

int t;
int n;

void solve()
{
    read(n);
    int res = n / 15 * 3;
    if(n % 15 == 0)
        res++;
    else if(n % 15 == 1)
        res += 2;
    else
        res += 3;
    cout << res << endl;
}

int main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
