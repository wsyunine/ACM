
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
int n, k;

void solve()
{
    vector<int> v;
    read(n), read(k);
    n--;
    int m = n + 1;
    if(n & 1) {
        v.push_back(k);
        v.push_back(k);
    }
    else {
        v.push_back(k);
        v.push_back(0);
    }

    n >>= 1;
    while(n) {
        if(n & 1) {
            int op = v.size();
            for(int i = 0; i < op; i++) {
                v.push_back(v[i]);
            }
        }
        else {
            int op = v.size();
            for(int i = 0; i < op; i++) {
                v.push_back(0);
            }
        }
        n >>= 1;
    }

    for(int i = 0; i < m; i++) printf("%lld ", v[i]);
    printf("\n");
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
