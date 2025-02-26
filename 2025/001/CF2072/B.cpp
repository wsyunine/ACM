
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
int n;
string str;
int op1, op2 = 0;

void solve()
{
    op1 = 0, op2 = 0;
    read(n);
    cin >> str;
    for(int i = 0; i < n; i++) {
        if(str[i] == '-')
            op1++;
        else
            op2++;
    }

    cout << (op1 / 2) * (op1 - op1 / 2) * op2 << endl;
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
