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

int n;
int a[N];

bool check(int x)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] > x) sum++;
    if(sum >= (n + 1) / 2)
        return 1;
    else
        return 0;
}

int main()
{
    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
    }

    int l = 0, r = 1e6;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;

    return 0;
}
