
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
int n, q;
ll w[N];
int pq[32][N], mp[32][N];

void solve()
{
    read(n);
    read(q);
    for(int i = 1; i <= n; i++) read(w[i]);

    for(ll i = 0; i <= 30; i++) {
        w[n + 1] = 0;
        for(int j = 1; j <= n + 1; j++) {
            if((w[j] >> i) & 1ll)
                pq[i][j] = j;
            else
                pq[i][j] = pq[i][j - 1];
        }
        mp[i][n + 1] = 0;
        for(int j = n; j >= 1; j--) {
            mp[i][j] = mp[i][j + 1] ^ ((w[j] >> i) & 1ll);
        }
    }

    for(int i = 1; i <= q; i++) {
        ll x;
        read(x);
        int l = 1, r = n + 1;
        for(ll i = 30; i >= 0; i--) {
            int y = ((x >> i) & 1ll) ^ mp[i][r];
            if(!y) {
                l = max(l, pq[i][r - 1] + 1);
            }
            else {
                int op1 = pq[i][r - 1];
                if(op1 == 0) {
                    break;
                }
                int op2 = pq[i][op1 - 1];
                l = max(l, op2 + 1);
                r = min(r, op1 + 1);
            }
            // cout << l << " " << r << endl;
        }

        cout << n - l + 1 << " ";
    }
    cout << endl;
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
