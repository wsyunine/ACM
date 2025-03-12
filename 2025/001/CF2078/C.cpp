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
int n;
int b[N];
unordered_map<int,int> mapp;
int pre[N],suf[N];

void solve() {
    mapp.clear();
    read(n);
    int sum=0;
    for(int i=1;i<=2*n;i++) read(b[i]),mapp[b[i]]=1;
    
    sort(b+1,b+1+2*n);
    reverse(b+1,b+1+2*n);

    for(int i=1;i<=2*n;i++) sum+=((i&1)==1?1:-1)*b[i];

    if(sum>0&&!mapp[sum]){
        cout<<sum<<" ";
        for(int i=1;i<=2*n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        return;
    }

    pre[1]=0;
    for(int i=2;i<=2*n;i++){
        pre[i]=pre[i-1]+((i&1)==0?1:-1)*b[i];
    }
    suf[2*n+1]=0;
    for(int i=2*n;i>=2;i--){
        suf[i]=suf[i+1]+((i&1)==1?1:-1)*b[i];
    }

    for(int i=1;i<=2*n;i++){
        int op=b[1]-pre[i]-suf[i+1];
        if(op<=0) continue;
        if(mapp[op]) continue;
        for(int j=1;j<=i;j++){
            cout<<b[j]<<" ";
        }
        cout<<op<<" ";
        for(int j=i+1;j<=2*n;j++){
            cout<<b[j]<<" ";
        }
        break;
    }
    cout<<endl;
}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}