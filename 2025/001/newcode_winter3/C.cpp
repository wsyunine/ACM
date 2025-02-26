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
string s[N];
int l, r, mx = 0;

int main()
{
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        mx = max(mx, (int)s[i].size());
    }

    sort(s + 1, s + 1 + n);

    read(l), read(r);

    if(n == 1) {
        cout << s[1].length() << endl;
        return 0;
    }

    int res = 0;
    for(int i = l; i <= r; i++) {
        if(i == l) {
            res += s[i].size();
            continue;
        }
        int op = 0;
        for(int j = 0; j < min(s[i].size(), s[i - 1].size()); j++) {
            if(s[i][j] != s[i - 1][j]) break;
            op++;
        }
        res += (s[i - 1].size() - op);
        res += (s[i].size() - op);
    }
    res += s[r].size();

    res -= mx;

    cout << res << endl;

    return 0;
}
