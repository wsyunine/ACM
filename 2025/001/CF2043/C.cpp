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
#include <unordered_map>
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

int T;
int n;
int a[N];
int mx1, mn1;

void solve()
{
    read(n);
    mx1 = mn1 = 0;
    for(int i = 1; i <= n; i++) read(a[i]);

    map<int, bool> mapp;

    int tmp = 0, mx = 0, mn = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1 || a[i] == -1) {
            tmp += a[i];
            mx1 = max(mx1, tmp - mn);
            mn1 = min(mn1, tmp - mx);
            mx = max(mx, tmp);
            mn = min(mn, tmp);
        }
        else {
            mx = 0;
            mn = 0;
            for(int j = mn1; j <= mx1; j++) mapp[j] = 1;
            mx1 = 0;
            mn1 = 0;
            tmp = 0;
        }
    }

    for(int j = mn1; j <= mx1; j++) mapp[j] = 1;

    int po = -1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != 1 && a[i] != -1) tmp = a[i], po = i;
    }

    // cerr << mx1 << " " << mn1 << endl;

    int mx2 = 0, mx3 = 0, mn2 = 0, mn3 = 0, op = 0;
    for(int i = po - 1; i >= 1; i--) {
        op = op + a[i];
        mx2 = max(op, mx2);
        mn2 = min(mn2, op);
    }
    op = 0;
    for(int i = po + 1; i <= n; i++) {
        op = op + a[i];
        mx3 = max(op, mx3);
        mn3 = min(op, mn3);
    }

    // cerr << mx2 << " " << mn2 << " " << mx3 << " " << mn3 << endl;

    mx2 = mx2 + mx3 + tmp;
    mn2 = mn2 + mn3 + tmp;

    if(po == -1) {
        mx2 = 0;
        mn2 = 0;
    }

    for(int i = mn2; i <= mx2; i++) {
        mapp[i] = 1;
    }

    printf("%lu\n", mapp.size());
    for(auto i : mapp) {
        printf("%lld ", i.first);
    }
    cout << endl;
}

signed main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
