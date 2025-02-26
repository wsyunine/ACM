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
int a[N];
int t;

void solve()
{
    read(n), read(m);
    if(m >= n) {
        printf("NO\n");
        return;
    }

    if(n <= 26) {
        printf("YES\n");
        for(int i = 1; i <= n - 1; i++) printf("%c", 'a' + i - 1);
        printf("%c", 'a' + m - 1);
        printf("\n");
        return;
    }

    if(n > m + 26) {
        printf("NO\n");
        return;
    }

    printf("YES\n");
    int x = n / 26, y = n % 26, k = m - n + 26;  // m=n-26+k

    vector<char> v;
    for(int i = 1, j = 'z'; i <= y + k; i++, j--) {
        if(j < 'a') j = 'z';
        v.push_back(j);
    }

    reverse(v.begin(), v.end());
    for(auto i : v) printf("%c", i);
    for(int i = 1; i < x; i++) {
        for(int j = 1; j <= 26; j++) printf("%c", 'a' + j - 1);
    }
    v.clear();
    for(int i = 1, j = 'z'; i <= 26 - k; i++, j--) v.push_back(j);
    reverse(v.begin(), v.end());
    for(auto i : v) printf("%c", i);
    printf("\n");
}

int main()
{
    read(t);
    while(t--) {
        solve();
    }

    return 0;
}
