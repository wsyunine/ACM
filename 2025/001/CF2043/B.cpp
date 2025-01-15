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
int a, b;

void solve()
{
    read(a), read(b);

    vector<int> ans;
    ans.push_back(1);

    if(b % 3 == 0 || a >= 3) ans.push_back(3);

    if(b == 5) ans.push_back(5);

    if(b == 7 || a >= 3) ans.push_back(7);

    if(b % 9 == 0 || (b % 3 == 0 && a >= 3) || (a >= 6)) ans.push_back(9);

    for(auto i : ans) printf("%d ", i);

    cout << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
