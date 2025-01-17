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
int k1, k2;

int a[N];

int main()
{
    read(n), read(k1), read(k2);

    int mx = 0;

    for(int i = 1; i <= n; i++) read(a[i]);

    for(int i = 1; i < n; i++) {
        mx = max(mx, a[i]);
    }

    if(mx > a[n]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
