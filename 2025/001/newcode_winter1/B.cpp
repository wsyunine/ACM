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

int n, d[N];

int main()
{
    read(n);
    for(int i = 1; i < n; i++) {
        int a, b;
        read(a), read(b);
        d[a]++;
        d[b]++;
    }

    for(int i = 1; i <= n; i++) {
        if(d[i] > 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(d[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
