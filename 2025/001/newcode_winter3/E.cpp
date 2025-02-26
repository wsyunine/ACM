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
int p[N], v[N];
vector<int> s1, s2;

bool check(int x)
{
    // cout << x << endl;
    int res = 0;
    for(auto i : s1) {
        int j = i + 2ll * x;
        // cout << j << " ";
        res += (upper_bound(s2.begin(), s2.end(), j) - upper_bound(s2.begin(), s2.end(), i));
    }
    // cout << res << endl;
    if(res >= k)
        return 1;
    else
        return 0;
}

signed main()
{
    read(n), read(k);

    for(int i = 1; i <= n; i++) read(p[i]), p[i] *= 2ll, read(v[i]), v[i] *= 2ll;
    for(int i = 1; i <= n; i++) {
        if(v[i] > 0)
            s1.push_back(p[i]);
        else
            s2.push_back(p[i]);
    }

    sort(s2.begin(), s2.end());

    int l = 0, r = 2000000100ll;
    while(r > l) {
        int mid = (l + r) >> 1ll;
        if(check(mid))
            r = mid;
        else
            l = mid + 1ll;
    }

    if(check(r)) {
        printf("Yes\n%.8f\n", (double)r / 2.0);
    }
    else {
        printf("No\n");
    }

    return 0;
}
