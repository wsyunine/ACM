
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
#define ll long long
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
ll x, k;
string s;

void solve()
{
    read(n), read(x), read(k);
    cin >> s;
    int res = 0;

    ll mv = 0, mxd;
    ll idea = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L')
            x--;
        else
            x++;
        k--;
        if(x == 0) {
            idea = 1;
            res++;
            break;
        }
        if(k == 0) {
            break;
        }
    }

    if(k == 0) {
        cout << res << endl;
        return;
    }

    if(idea) {
        idea = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L')
                mv--;
            else
                mv++;
            k--;
            if(mv == 0) {
                mxd = i + 1, res++, idea = 1;
                break;
            }
            if(k == 0) break;
        }
        if(k == 0) {
            cout << res << endl;
            return;
        }
        if(idea) res += k / mxd;
        cout << res << endl;
    }
    else {
        cout << res << endl;
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
