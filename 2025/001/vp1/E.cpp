#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
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
int a[N];

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}