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

int T;
int n;
int mapp[1010][1010];
pair<int, int> num[N];
int ans[N];

void solve()
{
    read(n);
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            mapp[i][j + 1] = s[j] - '0';
        }
        num[i] = {1, n};
    }

    for(int i = 1; i <= n; i++) {
        int op = 0;
        for(int j = 1; j < i; j++) {
            if(mapp[i][j]) op++;
        }
        for(int j = i + 1; j <= n; j++)
            if(!mapp[i][j]) op++;
        ans[op + 1] = i;
    }

    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
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
