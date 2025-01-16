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

int n, k;
int a[N], b[N];

bool check(double x)
{
    vector<double> s;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        s.push_back(100.0 * (double)a[i] - x * (double)b[i]);
    }

    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    double tmp = 0;
    int i;
    for(i = 0; i < n; i++) {
        tmp += s[i];
        if(tmp < 0) break;
    }
    if(i + k < n) return 0;
    return 1;
}

int main()
{
    while(cin >> n >> k) {
        if(n == 0 && k == 0) break;
        for(int i = 1; i <= n; i++) read(a[i]);
        for(int i = 1; i <= n; i++) read(b[i]);

        double l = 0, r = 100;
        while(r - l > 1e-3) {
            double mid = (l + r) / 2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }

        cout << round(l) << endl;
    }

    return 0;
}
