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
int dmin[N],dmax[N];
int n;
int a[N],b[N];

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    int opt=1;
    for(int i=1;i<=n;i++){
        while(b[opt]<a[i]) opt++;
        dmin[i]=b[opt]-a[i];
    }
    opt=1;
    for(int i=1;i<=n;i++){
        while(opt<n&&a[opt+1]<=b[opt]) opt++;
        if(i>opt) opt++;
        while(opt<n&&a[opt+1]<=b[opt]) opt++;
        dmax[i]=b[opt]-a[i];
    }
    for(int i=1;i<=n;i++){
        printf("%d ",dmin[i]);
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        printf("%d ",dmax[i]);
    }
    cout<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}