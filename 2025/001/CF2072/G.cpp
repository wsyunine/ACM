
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

int t;
int n;
int k;
int res = 0;
int p[N];

int cal(int x) { return (x + 1) * (2 * x + 1) * x / 6 % Mod; }

void solve()
{
    res = 0;
    read(n), read(k);

    if(n < 600 || k < 600) {
        for(int i = 2; i <= min(n, k); i++) {
            vector<int> v;
            int op = n, opt = 0;
            while(op) {
                v.push_back(op % i);
                op /= i;
            }
            reverse(v.begin(), v.end());
            for(int x = 0, j = 1; x < v.size(); x++, j *= i) {
                (opt += v[x] * j % Mod) %= Mod;
            }
            (res += opt) %= Mod;
        }
        if(k > n) (res += (k - n) % Mod * n % Mod) %= Mod;
        cout << res << endl;
        return;
    }

    int xp = 0;
    for(int i = 2; i <= 599; i++) {
        vector<int> v;
        int op = n, opt = 0;
        while(op) {
            v.push_back(op % i);
            op /= i;
        }
        reverse(v.begin(), v.end());
        for(int x = 0, j = 1; x < v.size(); x++, j *= i) {
            (opt += v[x] * j % Mod) %= Mod;
        }
        (res += opt) %= Mod;
        if(i >= 600) (xp += opt) %= Mod;
    }
    // cout << endl;
    // for(int i = 600; i <= 610; i++) cout << (n % i) * i + (n / i) << " ";
    // cout << endl;

    int xpp = 0, xpp1 = 0;

    for(int i = 1, j; i <= min(n, k); i = j + 1) {
        j = n / (n / i);
        if(j > min(n, k)) j = min(n, k);
        (res += (n / i) * (j - i + 1) % Mod) %= Mod;
        (res -= (n / i) * ((cal(j) - cal(i - 1) + Mod) % Mod) % Mod) %= Mod;
        res = (res + Mod) % Mod;
        // (xpp += (n / i) * (j - i + 1) % Mod) %= Mod;
        // (xpp1 -= (n / i) * (((i + j) * (j - i + 1) / 2ll) % Mod) % Mod) %= Mod;
        // xpp1 = (xpp + Mod) % Mod;
        // cout << i << " " << j << endl;
    }

    for(int i = 1, j; i <= 599; i = j + 1) {
        j = n / (n / i);
        if(j > 599) j = 599;
        (res -= (n / i) * (j - i + 1) % Mod) %= Mod;
        res = (res + Mod) % Mod;
        (res += (n / i) * ((cal(j) - cal(i - 1) + Mod) % Mod) % Mod) %= Mod;
        // (xpp -= (n / i) * (j - i + 1) % Mod) %= Mod;
        // xpp = (xpp + Mod) % Mod;
        // (xpp1 += (n / i) * (((i + j) * (j - i + 1) / 2ll) % Mod) % Mod) %= Mod;
        // cout << i << " " << j << endl;
    }

    (res += n * ((600 + min(n, k)) * (min(n, k) - 600 + 1) / 2) % Mod) %= Mod;
    // (xpp1 += n * ((600 + 600) * (600 - 600 + 1) / 2) % Mod) %= Mod;

    // cout << (n-n / 600*600) * 600 + (n / 600) << " " << xp << " " << xpp << endl;

    if(k > n) (res += (k - n) % Mod * n % Mod) %= Mod;
    cout << res << endl;
}

signed main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
