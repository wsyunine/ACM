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
int n,m,k;
int a[N];
int q[N],res[N];

void solve() {
    read(n),read(m),read(k);
    for(int i=1;i<=max(n,m);i++) q[i]=0,res[i]=0;
    for(int i=1;i<=m;i++) read(a[i]);
    for(int i=1;i<=k;i++){
        int op;
        read(op);
        q[op]++;
    }
    if(k<n-1){
        for(int i=1;i<=m;i++) cout<<0;
        cout<<endl;
        return;
    }else if(k==n){
        for(int i=1;i<=m;i++) cout<<1;
        cout<<endl;
        return;
    }
    int tmp=0;
    for(int i=1;i<=n;i++){
        if(!q[i]) tmp=i;
    }
    for(int i=1;i<=m;i++){
        if(a[i]==tmp){res[i]=1;}
    }
    for(int i=1;i<=m;i++) cout<<res[i];
    cout<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}