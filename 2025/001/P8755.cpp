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
int v[N];
int a[N], b[N], c[N], d[N];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

int main()
{
    read(n), read(m);

    for(int i = 1; i <= n; i++) read(v[i]);
    for(int i = 1; i <= m; i++) {
        read(a[i]), read(b[i]), read(c[i]), read(d[i]);
        q.push(make_pair(a[i], i));
    }

    while(q.size()) {
        auto t = q.top();
        q.pop();
        if(t.second > 0) {
            if(v[b[t.second]] >= d[t.second]) {
                v[b[t.second]] -= d[t.second];
                printf("%d\n", v[b[t.second]]);
                q.push(make_pair(a[t.second] + c[t.second], -t.second));
            }
            else {
                printf("-1\n");
            }
        }
        else {
            v[b[-t.second]] += d[-t.second];
        }
    }

    return 0;
}
