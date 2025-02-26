
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
int res = 0x3f3f3f3f;
int a[N], ans1, ans2;

void solve()
{
    read(n);
    res = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++) read(a[i]);
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j] < a[i]) sum++;
        }
    }

    for(int i = 1; i <= n; i++) {
        int op = 0, op1 = 0;
        for(int j = i + 1; j <= n; j++) {
            if(a[j] < a[i])
                op++;
            else if(a[j] > a[i])
                op1++;
            if(sum - op + op1 < res) {
                ans1 = i, ans2 = j;
                res = sum - op + op1;
            }
        }
    }

    if(res > sum) {
        cout << 1 << " " << 1 << endl;
    }
    else
        cout << ans1 << " " << ans2 << endl;
}

int main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
