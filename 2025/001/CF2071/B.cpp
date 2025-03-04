

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

int t;
int n;
int a[N];
int num[11] = {1, 8, 49, 288, 1681, 9800, 57121, 332928};
bool b[N];

void solve()
{
    read(n);
    if(b[n]) {
        cout << -1 << endl;
        return;
    }

    cout << 2 << " " << 1 << " ";
    for(int i = 3; i <= n; i++) {
        if(b[i])
            cout << i + 1 << " " << i << " ", i++;
        else
            cout << i << " ";
    }
    cout << endl;
}

signed main()
{
    for(int i = 0; i <= 7; i++) b[num[i]] = 1;
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
