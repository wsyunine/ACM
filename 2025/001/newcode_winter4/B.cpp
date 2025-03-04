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
const int Mod = 1e9 + 7;

int n;
int t;
string s, tmp;
int res = 0;

void check()
{
    if(tmp[1] == tmp[n]) {
        (res += n - 2) %= Mod;
    }
    else
        (res += 2ll) %= Mod;
}

void dfs(int po)
{
    if(po > n) {
        check();
        return;
    }
    if(s[po] != '?') {
        tmp.push_back(s[po]);
        dfs(po + 1);
        tmp.pop_back();
        return;
    }
    tmp.push_back('0');
    dfs(po + 1);
    tmp.pop_back();
    tmp.push_back('1');
    dfs(po + 1);
    tmp.pop_back();
}

signed main()
{
    read(t);
    while(t--) {
        res = 0;
        read(n);
        cin >> s;
        s = ' ' + s;

        if(s.size() == 2) {
            if(s[1] == '?')
                cout << 2 << endl;
            else
                cout << 1 << endl;
            continue;
        }

        tmp.clear();
        tmp.push_back(' ');
        dfs(1);

        cout << res << endl;
    }

    return 0;
}
