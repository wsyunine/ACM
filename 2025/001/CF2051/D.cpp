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
ll a[N];
ll x,y;

void solve() {
    read(n);read(x),read(y);
    ll sum=0;
    for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
    x=sum-x;
    y=sum-y;

    sort(a+1,a+1+n);

    ll res=0;
    for(int i=1;i<=n;i++){
        ll l=lower_bound(a+1,a+1+n,y-a[i])-a;
        ll r=upper_bound(a+1,a+1+n,x-a[i])-a-1;
        if(l>r) continue;
        res+=r-l+1;
        if(l<=i&&i<=r) res-=1;
    }
    cout<<res/2ll<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}