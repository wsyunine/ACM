
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

    int idea = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] >= a[i - 1]) {
            a[i] = a[i] - min(a[i], a[i - 1]);
        }
        else {
            idea = 0;
        }
    }

    if(idea)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
