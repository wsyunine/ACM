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
#define N 100010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int Mod=10000;

struct Matrix{
    int m,n;
    int a[110][110];

    inline void init(int _m=0,int _n=0){
        m=_m,n=_n;
        memset(a,0,sizeof a);
    }

    inline Matrix operator * (Matrix B){
        Matrix res;
        res.init(m,B.n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=B.n;j++){
                for(int k=1;k<=n;k++){
                    (res.a[i][j]+=a[i][k]*B.a[k][j])%=Mod;
                }
            }
        }
        return res;
    }

    inline void id(){
        for(int i=1;i<=m;i++) a[i][i]=1;
    }

    inline Matrix fpow(int t){
        Matrix res;
        res.init(m,m);
        res.id();
        Matrix tmp=*this;
        for(;t;t>>=1,tmp=tmp*tmp) if(t&1) res=res*tmp;
        return res;
    }
};

signed main(){

    Matrix op,ans;
    op.init(2,2);
    op.a[1][1]=op.a[1][2]=op.a[2][1]=1;
    op.a[2][2]=0;
    int n;
    while(cin>>n){
        if(n==-1) return 0;
        if(n==0) cout<<0<<endl;
        else if(n==1) cout<<1<<endl;
        else{
            ans=op.fpow(n-1);
            cout<<ans.a[1][1]<<endl;
        }
    }

    return 0;
}