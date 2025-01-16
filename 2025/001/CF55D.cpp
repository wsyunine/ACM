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
long long l, r;
vector<int> bit;
unordered_map<int, int> mapp;
size_t rev[50];
long long dp[20][50][2600];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b)
{
    if(!a || !b) return a + b;
    return a * b / gcd(a, b);
}

void init(int x, int pos)
{
    mapp[pos] = 1;
    if(x == 10) return;
    init(x + 1, lcm(x, pos));
    init(x + 1, pos);
}

long long query(int pos, int lim, int ll, int v)
{
    // cerr << pos << " " << lim << " " << ll << " " << v << endl;
    if(pos == 0) return dp[pos][mapp[ll]][v] = ll == 0 ? 0 : (v % ll == 0);
    // cerr << dp[pos][ll][v] << endl;
    if((!lim) && ~dp[pos][mapp[ll]][v]) return dp[pos][mapp[ll]][v];
    long long res = 0;
    if(lim) {
        for(int i = 0; i < bit[pos]; i++) {
            res += query(pos - 1, 0, lcm(ll, i), (v * 10 % 2520 + i) % 2520);
        }
        res += query(pos - 1, 1, lcm(ll, bit[pos]), (v * 10 % 2520 + bit[pos]) % 2520);
    }
    else {
        for(int i = 0; i <= 9; i++) {
            res += query(pos - 1, 0, lcm(ll, i), (v * 10 % 2520 + i) % 2520);
        }
    }
    if(!lim) dp[pos][mapp[ll]][v] = res;
    // cerr << pos << " " << lim << " " << ll << " " << v << endl;
    return res;
}

void solve()
{
    read(l), read(r);
    bit.clear();
    bit.push_back(0);
    while(r) bit.push_back(r % 10), r /= 10;
    long long res = query(bit.size() - 1, 1, 0, 0);
    bit.clear();
    bit.push_back(0);
    l--;
    while(l) bit.push_back(l % 10), l /= 10;
    res = res - query(bit.size() - 1, 1, 0, 0);
    cout << res << endl;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    init(2, 1);
    int cnt = 0;
    for(auto i : mapp) {
        mapp[i.first] = ++cnt;
        rev[cnt] = i.first;
    }

    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
