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
#define N 1510
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
int trie[N][11], cnt = 0, fail[N], num[N];
double val[N], dp[N][N];
int fd[N][N][2];
string cmd;
vector<int> ans(N + 10);

void insert(string s, double v)
{
    int x = 0;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        int ch = s[i] - '0';
        if(!trie[x][ch]) trie[x][ch] = ++cnt;
        x = trie[x][ch];
    }
    num[x]++;
    val[x] += log2(v);
}

void getfail()
{
    queue<int> q;
    for(int i = 0; i <= 9; i++) {
        if(trie[0][i]) fail[trie[0][i]] = 0, q.push(trie[0][i]);
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        int fafail = fail[x];
        num[x] += num[fail[x]];
        val[x] += val[fail[x]];
        for(int i = 0; i <= 9; i++) {
            int y = trie[x][i];
            if(!y) {
                trie[x][i] = trie[fafail][i];
                continue;
            }
            fail[y] = trie[fafail][i];
            q.push(y);
        }
    }
}

bool check(double s)
{
    // cout << s << endl;
    for(int i = 0; i <= cnt; i++) val[i] -= s * (double)num[i];
    // cout << endl;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= cnt; j++) dp[i][j] = -0x3f3f3f3f3f3f3f3f;

    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= cnt; j++) {
            for(int p = 0; p <= 9; p++) {
                if(cmd[i] == '.' || cmd[i] == p + '0') {
                    if(dp[i + 1][trie[j][p]] < dp[i][j] + val[trie[j][p]]) {
                        dp[i + 1][trie[j][p]] = dp[i][j] + val[trie[j][p]];
                        fd[i + 1][trie[j][p]][0] = j, fd[i + 1][trie[j][p]][1] = p;
                    }
                }
            }
        }
    }

    for(int i = 0; i <= cnt; i++) val[i] += s * (double)num[i];

    int op = 0;
    for(int i = 1; i <= cnt; i++)
        if(dp[n][i] > dp[n][op]) op = i;

    // cout << dp[n][op] << endl;

    if(dp[n][op] > 0) {
        int pos = op;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = fd[i + 1][pos][1] + '0';
            pos = fd[i + 1][pos][0];
        }
        return 1;
    }

    return 0;
}

int main()
{
    read(n), read(m);

    cin >> cmd;

    for(int i = 1; i <= m; i++) {
        string str;
        int k;
        cin >> str;
        read(k);
        insert(str, k);
    }

    getfail();

    // for(int i = 1; i <= cnt; i++) printf("%.20f ", val[i]);

    double l = 0, r = 1e9;
    while(r - l > 1e-6) {
        double mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }

    for(int i = 0; i < n; i++) printf("%c", ans[i]);
    cout << endl;
    return 0;
}
