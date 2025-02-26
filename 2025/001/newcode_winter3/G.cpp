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

int n, k;
vector<int> sum, val, fst;
int res = 0;

int check(int x)
{
    int op = 0;
    res = 0;
    for(int i = 0; i < sum.size(); i++) {
        if(fst[i] > x) continue;
        int xl = 0, xr = 1e9;
        while(xl < xr) {
            int mid = (xl + xr + 1) >> 1;
            if(fst[i] + mid * val[i] > x)
                xr = mid - 1;
            else
                xl = mid;
        }
        int ip = min(xl + 1, sum[i]);
        op += min(xl + 1, sum[i]);
        res += (fst[i] + fst[i] + (ip - 1) * val[i]) * ip / 2;
    }
    return op;
}

signed main()
{
    read(n), read(k);

    for(int i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        sum.push_back(j - i + 1);
        val.push_back(n / i);
        fst.push_back(i * (n / i));
    }

    int l = n / 2, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }

    // cout << l << endl;

    int x = check(l);

    // cout << x << endl;

    cout << k * n - (res - l * (x - k)) << endl;

    return 0;
}
