
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
int n, x;

void solve()
{
    read(n), read(x);
    if(n == 1) {
        printf("%lld\n", x);
        return;
    }

    int tmp = 0, i = 1;
    vector<int> v;
    v.push_back(0);
    while((((tmp | i) | x) - x == 0) && v.size() < n) {
        tmp |= i;
        v.push_back(i);
        i++;
    }
    while(v.size() < n) {
        v.push_back(x);
        tmp |= x;
    }
    if(tmp != x) {
        v.pop_back();
        for(auto i : v) printf("%lld ", i);
        printf("%lld\n", x);
    }
    else {
        for(auto i : v) printf("%lld ", i);
        printf("\n");
    }
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
