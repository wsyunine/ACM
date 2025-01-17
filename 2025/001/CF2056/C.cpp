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

void solve()
{
    read(n);

    if(n & 1) {
        cout << 1 << " ";
        for(int i = 1; i <= n / 2; i++) {
            cout << i << " ";
        }
        for(int i = 1; i <= n / 2; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << 1 << " ";
        for(int i = 1; i <= n / 2; i++) {
            cout << i << " ";
        }
        for(int i = 1; i <= n / 2 - 1; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
