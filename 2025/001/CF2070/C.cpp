
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
int k;
string s;
int a[N];

bool check(int x)
{
    char st = 'R';
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > x) {
            if(s[i] == 'B' && st == 'R') {
                res++;
                st = 'B';
            }
            else if(s[i] == 'R' && st == 'B') {
                st = 'R';
            }
        }
    }
    if(res <= k) return 1;
    return 0;
}

void solve()
{
    read(n), read(k);
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; i++) read(a[i]);

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
}

int main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
