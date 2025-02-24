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
string s;
int mapp[N];
int res = 0;

int main()
{
    read(n);
    cin >> s;
    s = ' ' + s;

    for(int i = 1; i <= n; i++) {
        if(!mapp[s[i]])
            mapp[s[i]] = i;
        else
            res = max(res, mapp[s[i]]), mapp[s[i]] = i;
    }
    for(int i = 'a'; i <= 'z'; i++) mapp[i] = 0;
    for(int i = n; i >= 1; i--) {
        if(!mapp[s[i]])
            mapp[s[i]] = i;
        else
            res = max(res, n - mapp[s[i]] + 1), mapp[s[i]] = i;
    }

    cout << ((res == 1) ? 0 : res) << endl;

    return 0;
}
