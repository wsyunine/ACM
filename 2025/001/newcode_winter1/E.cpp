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

int T;

int n, a[N];
ll res1 = 0, res2 = 0;

int main()
{
    read(T);
    while(T--) {
        read(n);
        res1 = 0, res2 = 0;
        for(int i = 1; i <= n; i++) read(a[i]);

        sort(a + 1, a + 1 + n);

        int x1, x2;
        if((n / 2) % 2)
            x1 = a[(n / 2) / 2 + 1];
        else
            x1 = (a[(n / 2) / 2] + a[(n / 2) / 2 + 1]) / 2;

        if((n / 2) % 2)
            x2 = a[(n / 2) + (n / 2) / 2 + 1];
        else
            x2 = (a[(n / 2) + (n / 2) / 2] + a[(n / 2) + (n / 2) / 2 + 1]) / 2;

        if(x1 == x2) {
            x1--;

            for(int i = 1; i <= n / 2; i++) {
                res1 += abs(a[i] - x1);
            }
            for(int i = n / 2 + 1; i <= n; i++) {
                res1 += abs(a[i] - x2);
            }

            x1++;
            x2++;

            for(int i = 1; i <= n / 2; i++) {
                res2 += abs(a[i] - x1);
            }
            for(int i = n / 2 + 1; i <= n; i++) {
                res2 += abs(a[i] - x2);
            }

            cout << min(res1, res2) << endl;
        }
        else {
            for(int i = 1; i <= n / 2; i++) {
                res1 += abs(a[i] - x1);
            }

            for(int i = n / 2 + 1; i <= n; i++) {
                res1 += abs(a[i] - x2);
            }

            cout << res1 << endl;
        }
    }

    return 0;
}
