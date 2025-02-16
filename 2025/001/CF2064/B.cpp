
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
int a[N], b[N];
int num[N];

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) num[i] = 0;
    for(int i = 1; i <= n; i++) read(a[i]), num[a[i]]++;
    for(int i = 1; i <= n; i++) {
        if(num[a[i]] == 1) {
            b[i] = 1;
        }
        else {
            b[i] = 0;
        }
    }
    b[0] = 0;

    int res = 0;
    int ans = 0;
    int l, r;
    for(int i = 1; i <= n; i++) {
        if(b[i] == 1 && b[i - 1] == 1) {
            res++;
            if(res > ans) {
                ans = res;
                l = i - res + 1;
                r = i;
            }
        }
        else if(b[i] == 1) {
            res = 1;
            if(res > ans) {
                ans = res;
                l = i - res + 1;
                r = i;
            }
        }
        else {
            res = 1;
        }
    }

    if(n == 1) {
        cout << 1 << " " << 1 << endl;
        return;
    }

    if(!ans) {
        cout << 0 << endl;
    }
    else {
        cout << l << " " << r << endl;
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
