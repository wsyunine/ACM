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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int Mod;
int n,k;

struct Matrix{
    int m,n;
    int a[110][110];

    inline void init(int _m=0,int _n=0){
        m=_m,n=_n;
        memset(a,0,sizeof a);
    }

    inline Matrix operator + (Matrix B){
        Matrix res;
        // cout<<"+"<<endl;
        res.init(m,n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                res.a[i][j]=(a[i][j]+B.a[i][j])%Mod;
            }
        }
        return res;
    }

    inline Matrix operator * (Matrix B){
        Matrix res;
        // cout<<"*"<<endl;
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
        // cout<<" "<<t<<endl;
        res.init(m,m);
        res.id();
        Matrix tmp=*this;
        for(;t;t>>=1,tmp=tmp*tmp) if(t&1) res=res*tmp;
        return res;
    }
};

Matrix powsum(Matrix A,int kk){
    if(kk==1) return A;
    Matrix I,res,res2;
    I.init(A.m,A.m);
    if(kk<=0) return I;
    I.id();
    res2=powsum(A,kk>>1);
    res=(I+A.fpow(kk>>1))*res2;
    if(kk&1) return res+A.fpow(kk);
    return res;
}

signed main(){

    read(n),read(k),read(Mod);
    Matrix op,ans;
    op.init(n,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            read(op.a[i][j]);
        }
    }

    ans=powsum(op,k);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans.a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}