#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
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
int n,m;
int a[N],b[N];

void solve() {
    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int j=1;j<=m;j++) read(b[j]);

    sort(b+1,b+1+m);

    if(n==1){
        cout<<"Yes"<<endl;
        return;
    }

    a[1]=min(a[1],b[1]-a[1]);

    for(int i=2;i<=n;i++){
        int op=lower_bound(b+1,b+1+m,a[i]+a[i-1])-b;
        // cerr<<op<<" ";
        if(op==m+1){
            if(a[i]<a[i-1]){
                cout<<"No"<<endl;
                return;
            }
        }else{
            if(a[i]>=a[i-1]){
                a[i]=min(a[i],b[op]-a[i]);
            }else a[i]=b[op]-a[i];
        }
        // cerr<<a[i]<<endl;
    }

    cout<<"Yes"<<endl;
}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}