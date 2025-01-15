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

int T;
int n, m, res = 0, resx = 1;
int mapp[1010][1010];
vector<pair<int, int> > ans;
int r[1010], c[1010], rx[1010], cx[1010];
string pat;

void solve()
{
    read(n), read(m);
    cin >> pat;
    res = 0;
    resx = 1;
    ans.clear();

    for(int i = 1; i <= n; i++) {
        r[i] = 0;
        rx[i] = 0;
        for(int j = 1; j <= m; j++) {
            read(mapp[i][j]);
            r[i] += mapp[i][j];
        }
    }

    for(int i = 1; i <= m; i++) {
        c[i] = 0;
        cx[i] = 0;
        for(int j = 1; j <= n; j++) {
            c[i] += mapp[j][i];
        }
    }

    rx[1] = cx[1] = 1;

    int x = 1, y = 1;
    for(int i = 0; i < pat.size(); i++) {
        // cerr << x << " " << y << endl;
        if(i == 0) {
            if(pat[i] == 'D') {
                res = r[1];
            }
            else {
                res = c[1];
            }
            ans.push_back(make_pair(1, 0));
        }
        else {
            if(pat[i] == 'D') {
                int a = res - r[x];
                int b = resx - rx[x];
                ans.push_back(make_pair(b, a));
                r[x] += a;
                c[y] += a;
                rx[x] += b;
                cx[y] += b;
            }
            else {
                int a = res - c[y];
                int b = resx - cx[y];
                ans.push_back(make_pair(b, a));
                c[y] += a;
                r[x] += a;
                cx[y] += b;
                rx[x] += b;
            }
        }
        if(pat[i] == 'D') {
            x++;
        }
        else {
            y++;
        }
    }

    int op1 = resx - cx[m];
    int op2 = res - c[m];
    int op3 = resx - rx[n];
    int op4 = res - r[n];

    int op = (op1 == op3) ? 0 : (op4 - op2) / (op1 - op3);

    x = 1, y = 1;
    for(int i = 0; i < pat.size(); i++) {
        mapp[x][y] = ans[i].first * op + ans[i].second;
        if(pat[i] == 'D') {
            x++;
        }
        else {
            y++;
        }
    }

    mapp[x][y] = op1 * op + op2;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%lld ", mapp[i][j]);
        }
        printf("\n");
    }
}

signed main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
