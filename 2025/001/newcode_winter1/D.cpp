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
#include <unordered_map>
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
int n, a[N];
unordered_map<int, int> mapp;

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    mapp.clear();
    for(int i = 1; i <= n; i++) {
        mapp[a[i]]++;
    }
    int idea1 = 0, idea2 = 0;
    for(auto i : mapp) {
        if(!idea1)
            idea1 = i.first;
        else
            idea2 = i.first;
    }
    if(n % 2 == 0 && mapp.size() == 2 && mapp[idea1] == mapp[idea2]) {
        cout << "Yes" << endl;
    }
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
