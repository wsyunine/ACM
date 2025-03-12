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
int b[N];

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    b[n+1]=0;

    int res=0;
    for(int i=1;i<=n;i++){
        if(b[i+1]<a[i]) res+=a[i]-b[i+1];
    }
    cout<<res<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}