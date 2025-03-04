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
const ll Mod = 1e9 + 7;

int n;
int t;
string s;
ll res1 = 0, res2 = 0;

int main()
{
    read(t);
    while(t--) {
        res1 = 0, res2 = 0;
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

        if(s[1] == '?' && s[n] == '?') {
            res1 += 2ll;
            res2 += 2ll;
        }
        else if(s[1] == '?' || s[n] == '?') {
            res1 += 1ll;
            res2 += 1ll;
        }
        else {
            if(s[1] == s[n])
                res1 += 1ll;
            else
                res2 += 1ll;
        }

        ll op = 1;
        for(int i = 2; i <= n - 1; i++) {
            if(s[i] == '?') (op *= 2ll) %= Mod;
        }

        cout << (res1 * op % Mod * (n - 2ll) % Mod + res2 * op % Mod * 2ll % Mod) % Mod << endl;
    }

    return 0;
}
