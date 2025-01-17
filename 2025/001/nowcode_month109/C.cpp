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
int q;
set<int> s;
int res[N];

int main()
{
    read(n), read(q);
    for(int i = 1; i <= n; i++) {
        s.insert(i);
        res[i] = 0;
    }

    int cnt = 0;
    while(q--) {
        int op;
        int l, r, x;
        read(op);
        if(op == 1) {
            read(l), read(r);
            if(s.empty()) continue;
            auto op1 = s.lower_bound(l);
            auto op2 = s.upper_bound(r);
            while(op1 != op2) {
                res[*op1] = ++cnt;
                ++op1;
                auto p = op1;
                p--;
                s.erase(p);
            }
        }
        else {
            read(x);
            printf("%d\n", res[x]);
        }
    }

    return 0;
}
