#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;
#define N 500010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
int q;
int a[N],b[100],c[100];

void ins(int x){
    for(int i=63;i>=0;i--){
        if((x&(1ll<<i))==0) continue;
        if(!b[i]){b[i]=x;return;}
        else x^=b[i];
    }
}

signed main(){

    int o=1;
    read(t);
    while(t--){
        cout<<"Case #"<<o<<":"<<endl;
        o++;
        for(int i=0;i<=90;i++) b[i]=c[i]=0;
        read(n);
        int cnt=0;
        for(int i=1;i<=n;i++) read(a[i]),ins(a[i]);
        read(q);
        for(int i=0;i<64;i++){
            for(int j=i-1;j>=0;j--){
                if(b[i]&(1ll<<j)) b[i]^=b[j];
            }
            if(b[i]) c[cnt++]=b[i];
        }
        for(int i=1;i<=q;i++){
            int op,res=0;
            read(op);
            if(cnt!=n) op--;
            if(!op){cout<<0<<endl;continue;}
            if(op>=(1ll<<cnt)){cout<<-1<<endl;continue;}
            for(int i=0;i<cnt;i++){
                if(op&(1ll<<i)) res^=c[i];
            }
            cout<<res<<endl;
        }
    }

    return 0;
}