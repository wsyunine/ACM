
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
int sp[N];

void solve()
{
    read(n);
    int xx = 0, yy = 0, sum = 0;
    vector<pair<int, int>> ans;
    while(n) {
        int x = upper_bound(sp + 1, sp + 1 + 500, n) - sp - 1;
        sum += x;
        for(int i = yy + 1; i <= yy + x; i++) ans.push_back({xx, i});
        yy = yy + x;
        xx++;
        n -= sp[x];
    }

    printf("%d\n", sum);
    for(auto i : ans) {
        printf("%d %d\n", i.first, i.second);
    }
}

int main()
{
    for(int i = 2; i <= 500; i++) {
        sp[i] = i * (i - 1) / 2;
    }

    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
