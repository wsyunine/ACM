
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
int a[N];

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + 1 + n);

    int tmp = 0, op1, op2;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] == a[i + 1]) {
            op1 = i, op2 = i + 1, tmp = a[i];
            break;
        }
    }

    if(!tmp) {
        cout << -1 << endl;
        return;
    }

    for(int i = 1; i < n; i++) {
        if(i == op1) {
            i += 1;
            continue;
        }
        if(i + 1 == op1) {
            if(i + 3 > n) break;
            if(a[i] + 2 * tmp > a[i + 3]) {
                cout << a[i] << " " << tmp << " " << tmp << " " << a[i + 3] << endl;
                return;
            }
            i = i + 3;
            continue;
        }
        if(a[i] + 2 * tmp > a[i + 1]) {
            cout << a[i] << " " << tmp << " " << tmp << " " << a[i + 1] << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
