
#include <bits/stdc++.h>

#include <algorithm>
#include <queue>

using namespace std;

#define N 200010

template <typename T>
inline void read(T &x)
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
int m;
int k;
int a[N];
int num[N];
int ans = 0;

signed main()
{
    read(n), read(m);
    read(k);

    for(int i = 1; i <= n; i++) num[i] = 0;

    for(int i = 1; i <= n; i++) read(a[i]), num[a[i]]++;

    int tmp = 0;
    int op = 0;
    // op position get 1-n
    for(int i = 1; i <= n; i++) {
        tmp += num[i];
        if(tmp >= n - k) {
            tmp -= num[i];
            ans += i * (n - k - tmp);
            tmp = n - k;
            op = i;
            break;
        }
        else {
            ans += i * num[i];
        }
    }

    while(m--) {
        int x, y;
        read(x), read(y);
        if((a[x] < op && a[y] < op) || (a[x] > op && a[y] > op)) {
            num[a[x]]--;
            a[x] = a[y];
            num[a[x]]++;
        }
        else if(a[x]) {
        }
    }

    return 0;
}
