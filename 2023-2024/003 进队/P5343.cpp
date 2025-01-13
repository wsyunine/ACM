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
#define N 1000010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const ll Mod=1e9+7;
ll nn,m1,m2;
bool vis[110][2];

struct Matrix{
    int m,n;
    ll a[110][110];

    void init(int _m=0,int _n=0){
        m=_m,n=_n;
        memset(a,0,sizeof a);
    }

    Matrix operator + (Matrix B){
        Matrix res;
        res.init(m,n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                res.a[i][j]=a[i][j]+B.a[i][j];
            }
        }
        return res;
    }

    Matrix operator - (Matrix B){
        Matrix res;
        res.init(m,n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                res.a[i][j]=a[i][j]-B.a[i][j];
            }
        }
        return res;
    }

    Matrix operator * (int c){
        Matrix res;
        res.init(m,n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                res.a[i][j]=c*a[i][j];
            }
        }
        return res;
    }

    Matrix operator * (Matrix B){
        Matrix res;
        res.init(m,B.n);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=B.n;j++){
                for(int k=1;k<=n;k++){
                    (res.a[i][j]+=(a[i][k]*B.a[k][j]%Mod))%=Mod;
                }
            }
        }
        return res;
    }

    void id(){
        for(int i=1;i<=m;i++) a[i][i]=1;
    }

    Matrix fpow(ll t){
        Matrix res;
        res.init(m,m);
        res.id();
        Matrix tmp=*this;
        for(;t;t>>=1,tmp=tmp*tmp) if(t&1) res=res*tmp;
        return res;
    }
}op,st;

int main(){

    read(nn);read(m1);
    for(int i=1,j;i<=m1;i++) read(j),vis[j][0]=1;
    read(m2);
    for(int i=1,j;i<=m2;i++) read(j),vis[j][1]=1;
    vector<int> s;

    for(int i=1;i<=min((ll)100,nn);i++) if(vis[i][0]&&vis[i][1]) s.push_back(i);

    int len=s.size();
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<len;j++){
    //         if(s[j]<i) (dp[i]+=dp[i-s[j]])%=Mod;
    //     }
    // } 

    op.init(min((ll)100,nn),min((ll)100,nn));
    st.init(min((ll)100,nn),1);

    for(int i=0;i<len;i++) op.a[1][s[i]]=1;
    for(int i=2;i<=min((ll)100,nn);i++) op.a[i][i-1]=1;

    st.a[1][1]=1;

    op=op.fpow(nn);

    st=op*st;

    cout<<st.a[1][1]%Mod<<endl;

    return 0;
}