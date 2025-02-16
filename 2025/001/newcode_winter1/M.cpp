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

int n;
int a[N], mxp[N], mnp[N], mxs[N], mns[N];
int res = 0x3f3f3f3f3f3f3f3f;
int num[N];

bool cmp(int x, int y) { return a[x] < a[y]; }

signed main()
{
    memset(mnp, 0x3f, sizeof mnp);
    memset(mns, 0x3f, sizeof mns);
    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        num[i] = i;
        mxp[i] = max(mxp[i - 1], a[i]);
        mnp[i] = min(mnp[i - 1], a[i]);
    }
    for(int i = n; i >= 1; i--) {
        mxs[i] = max(mxs[i + 1], a[i]);
        mns[i] = min(mns[i + 1], a[i]);
    }
    a[n + 1] = 0x3f3f3f3f3f3f3f3f;

    sort(num + 1, num + 1 + n, cmp);

    a[num[1]] *= 2;
    res = max(max(a[num[1]], mxp[num[1] - 1]), mxs[num[1] + 1]) -
          min(min(a[num[1]], mnp[num[1] - 1]), mns[num[1] + 1]);

    int l = num[1], r = num[1], mnn = a[l], mxx = a[l];
    for(int i = 2; i <= n; i++) {
        if(l <= num[i] && r >= num[i]) {
            continue;
        }
        if(l > num[i]) {
            while(l > num[i]) {
                l--;
                a[l] *= 2;
                mxx = max(mxx, a[l]);
                mnn = min(mnn, a[l]);
            }
            res = min(
                res, max(max(mxx, mxp[l - 1]), mxs[r + 1]) - min(min(mnn, mnp[l - 1]), mns[r + 1]));
        }
        else {
            while(r < num[i]) {
                r++;
                a[r] *= 2;
                mxx = max(mxx, a[r]);
                mnn = min(mnn, a[r]);
            }
            res = min(
                res, max(max(mxx, mxp[l - 1]), mxs[r + 1]) - min(min(mnn, mnp[l - 1]), mns[r + 1]));
        }
    }

    cout << res << endl;

    return 0;
}
