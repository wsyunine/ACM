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

int n, q;
int s[N];
int e[N], ne[N], h[N], idx;
vector<int> p[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int main()
{
    read(n), read(q);
    for(int i = 1; i <= n; i++) {
        read(s[i]);
        for(int j = 1; j <= s[i]; j++) {
        }
    }

    return 0;
}
