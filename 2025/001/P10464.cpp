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

int n, m;
pair<int, int> a[N];
pair<long long, long long> b[N];
long long c[N], cnt = 0, ans = 0;

int main()
{
    read(n), read(m);
    for(int i = 1; i <= n; i++) read(a[i].first), read(a[i].second);
    for(int i = 1; i <= m; i++) read(b[i].first), read(b[i].second);

    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    reverse(b + 1, b + 1 + m);

    int p = 0;
    for(int i = 1; i <= m; i++) {
        while(p < n && a[p + 1].first >= b[i].first) p++, c[a[p].second]++;
        for(int j = b[i].second; j <= 100; j++) {
            if(c[j]) {
                cnt++;
                c[j]--;
                ans += b[i].first * 500LL + b[i].second * 2LL;
                break;
            }
        }
    }

    cout << cnt << " " << ans << endl;

    return 0;
}
