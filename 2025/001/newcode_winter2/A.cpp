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

int n;
int a[N];

int main()
{
    int idea = 1;
    for(int i = 1; i <= 7; i++) {
        read(a[i]);
        if(a[i] != 1 && a[i] != 2 && a[i] != 3 && a[i] != 5 && a[i] != 6) idea = 0;
    }

    if(idea)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
