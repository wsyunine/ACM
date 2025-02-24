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

int t;
int a, b, c, d;

int main()
{
    read(t);
    while(t--) {
        read(a), read(b), read(c), read(d);

        if(b - a >= d - c)
            printf("%d %d\n%d %d\n%d %d\n", a, d - 1, b - 1, d, b, d);
        else
            printf("%d %d\n%d %d\n%d %d\n", a + 1, c, a, d - 1, a, d);
    }

    return 0;
}
