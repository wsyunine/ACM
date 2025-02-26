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
int mapp[5][N], mpp[11];
int sum1, sum2, sum3;
int ans = 1;

int C(int x, int y)
{
    int res = 1;
    for(int i = x, j = 1; j <= y; j++, i--) {
        res *= i;
    }
    for(int i = 1; i <= y; i++) {
        res /= i;
    }
    return res % Mod;
}

int A(int x)
{
    int res = 1;
    for(int i = 1; i <= x; i++) res *= i;
    return res % Mod;
}

void solve()
{
    sum1 = sum2 = sum3 = 0;
    for(int i = 1; i <= 9; i++) mpp[i] = 0;
    read(n);
    for(int i = 1; i <= 3; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= n; j++) {
            mapp[i][j] = (str[j - 1] == '?' ? -1 : str[j - 1] % '0');
        }
    }

    int idea = 1;
    set<int> s;
    for(int i = 1; i <= n; i += 3) {
        vector<int> mp(11, 0);
        for(int j = 1; j <= 3; j++) {
            if(mapp[j][i] == -1) continue;
            if(mp[mapp[j][i]]) idea = 0;
            mp[mapp[j][i]] = 1;
            s.insert(mapp[j][i]);
        }
    }
    for(auto i : s) mpp[i] = 1;
    if(s.size() > 3) idea = 0;
    sum1 = s.size();
    s.clear();
    for(int i = 2; i <= n; i += 3) {
        vector<int> mp(11, 0);
        for(int j = 1; j <= 3; j++) {
            if(mapp[j][i] == -1) continue;
            if(mp[mapp[j][i]]) idea = 0;
            mp[mapp[j][i]] = 1;
            s.insert(mapp[j][i]);
        }
    }
    for(auto i : s) {
        if(mpp[i]) idea = 0;
        mpp[i] = 2;
    }
    if(s.size() > 3) idea = 0;
    sum2 = s.size();
    s.clear();
    for(int i = 3; i <= n; i += 3) {
        vector<int> mp(11, 0);
        for(int j = 1; j <= 3; j++) {
            if(mapp[j][i] == -1) continue;
            if(mp[mapp[j][i]]) idea = 0;
            mp[mapp[j][i]] = 1;
            s.insert(mapp[j][i]);
        }
    }
    for(auto i : s) {
        if(mpp[i]) idea = 0;
        mpp[i] = 3;
    }
    if(s.size() > 3) idea = 0;
    sum3 = s.size();
    s.clear();

    if(!idea) {
        printf("0\n");
        return;
    }

    int op = 9 - sum1 - sum2 - sum3;

    ans = 1;

    (ans *= C(op, 3 - sum1)) %= Mod;
    (ans *= C(op - (3 - sum1), 3 - sum2)) %= Mod;
    (ans *= C(op - (3 - sum1) - (3 - sum2), 3 - sum3)) %= Mod;

    for(int i = 1; i <= n; i++) {
        int opt = 0;
        for(int j = 1; j <= 3; j++) {
            if(mapp[j][i] == -1) opt++;
        }
        (ans *= A(opt)) %= Mod;
    }

    printf("%lld\n", ans);

    return;
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
