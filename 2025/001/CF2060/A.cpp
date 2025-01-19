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
    int a, b, c, d;
    read(a), read(b), read(c), read(d);
    int op1 = a + b;
    int op2 = c - b;
    int op3 = d - c;
    set<int> s;
    s.insert(op1);
    s.insert(op2);
    s.insert(op3);
    cout << 4 - s.size() << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
