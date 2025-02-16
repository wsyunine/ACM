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

int n, a[N];
ll num[N];
ll res = 0;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]), num[a[i]]++;

    for(int i = 1; i <= 2e5; i++) {
        for(int j = 2 * i; j <= 2e5; j += i) {
            if(gcd(j ^ i, j) == i) res += num[j] * num[j ^ i];
        }
    }

    cout << res / 2 << endl;

    return 0;
}
