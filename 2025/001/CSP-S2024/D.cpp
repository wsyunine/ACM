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
#define N 1000010
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

int T, n, m, b[N], a[N], c[N], f[N];
int fa[N], w[N], d[N], ch[N][2], res[N];
int cnt = 0, k;
bool is_free[N];

void add(int a, int b) { fa[a] = b; }

int main()
{
    read(n), read(m);
    for(int i = 1; i <= n; i++) read(b[i]);
    for(int i = 1; i <= m; i++) read(c[i]);

    k = log2(n - 1) + 1;

    queue<int> q;
    for(int i = 1; i <= (1 << k); i++) q.push(i);
    cnt = 1 << k;
    for(int i = k - 1; i >= 0; i--) {
        // cerr << i << endl;
        int j = 1 << i, op = 0;
        string s;
        cin >> s;
        while(j--) {
            int y, z;
            cnt++;
            d[cnt] = (s[op] == '0') ? 0 : 1;
            op++;
            y = q.front();
            q.pop();
            z = q.front();
            q.pop();
            add(y, cnt);
            add(z, cnt);
            ch[cnt][0] = y, ch[cnt][1] = z;
            q.push(cnt);
        }
    }

    read(T);
    while(T--) {
        int x[5];
        for(int i = 0; i <= 3; i++) read(x[i]);

        for(int i = 1; i <= n; i++) {
            a[i] = b[i] ^ x[i % 4];
            // cerr << a[i] << " ";
            w[i] = 0;
        }
        // cerr << endl;

        for(int i = 1; i <= cnt; i++) {
            is_free[i] = 0;
            if(i <= (1 << k))
                res[i] = i;
            else
                res[i] = res[ch[i][0]] + res[ch[i][1]];
        }

        for(int i = 1; i <= n; i++) {
            is_free[i] = 1;
            w[i] = a[i];
            int tmp = i, s = (i == 1) ? 0 : log2(i - 1) + 1, j = 1;
            while(s--) {
                int op1 = tmp & 1;
                tmp = fa[tmp];
                /*
                if(is_free[ch[tmp][d[tmp]]]) {
                    is_free[tmp] = 1;
                    res[tmp] = res[ch[tmp][0]] + res[ch[tmp][1]];
                }
                else if(w[ch[tmp][d[tmp]]] >= j) {
                    is_free[tmp] = 0;
                    res[tmp] = res[ch[tmp][d[tmp]]];
                    w[tmp] = w[ch[tmp][d[tmp]]];
                }
                else {
                    is_free[tmp] = is_free[ch[tmp][d[tmp] ^ 1]];
                    res[tmp] = res[ch[tmp][d[tmp] ^ 1]];
                    w[tmp] = w[ch[tmp][d[tmp] ^ 1]];
                }
                */

                j++;
            }
            f[i] = res[tmp];
            cerr << f[i] << " ";
        }
        cerr << endl;

        long long ans = 0;
        for(int i = 1; i <= m; i++) {
            ans = ans ^ (i * f[c[i]]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
