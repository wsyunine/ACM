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
#define N 1000010
using ll = long long;
template <typename T>
inline void read(T &x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}
const ll Mod = 19930726;

int n;
ll k;
string str;
ll jc[N], ans = 1;
int p[N], cnt[N];
priority_queue<int> q;

ll fpow(ll a, ll b)
{
    ll res = 1;
    for(; b; b >>= 1, a = a * a % Mod)
        if(b & 1) res = res * a % Mod;
    return res;
}

int main()
{
    read(n), read(k);
    cin >> str;
    str = '#' + str;

    for(int t = 1, r = 0, mid = 0; t <= n; t++) {
        if(t <= r) p[t] = min(p[(mid << 1) - t], r - t + 1);
        while(str[t - p[t]] == str[t + p[t]]) ++p[t];
        if(p[t] + t > r) r = p[t] + t - 1, mid = t;
        cnt[2 * p[t] - 1]++;
    }

    ll tmp = 0, s = 0;
    for(int i = n; i >= 1; i--) {
        if(i % 2 == 0) continue;
        if(tmp == k) break;
        s += cnt[i];
        if(tmp + s > k) {
            ans = ans * fpow(i, k - tmp) % Mod;
            tmp = k;
            break;
        }
        else {
            ans = ans * fpow(i, s) % Mod;
            tmp += s;
        }
    }

    if(tmp >= k)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}
