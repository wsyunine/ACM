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
const int Mod=1e9+7;

int n;
int q;
int phi[N];
int mindiv[N],pri[N],cnt=0;

void getphi(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=mindiv[i]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||pri[j]*i>n) break;
            mindiv[pri[j]*i]=pri[j];
            phi[pri[j]*i]=phi[i]*((i%pri[j])?(pri[j]-1):pri[j]);
        }
    }
}

signed main(){

    read(n),read(q);
    vector<vector<int>> r(n+2),c(n+2);
    getphi(n+2);
    for(int i=1;i<=n;i++){
        r[i].push_back(0),c[i].push_back(0);
        for(int j=1;j<=n/i;j++) r[i].push_back(1),c[i].push_back(1);
        r[i][0]=n/i;c[i][0]=n/i;
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int rr=0,cc=0;
        for(int j=1;j<=n/i;j++){
            (rr+=r[i][j])%=Mod;
            (cc+=c[i][j])%=Mod;
        }
        (ans+=phi[i]*rr%Mod*cc%Mod)%=Mod;
    }

    for(int i=1;i<=q;i++){
        char s;int op;
        cin>>s;
        int x,y;
        read(x),read(y);
        if(s=='R'){
            for(int j=1;j*j<=x;j++){
                if(x%j==0){
                    ans=(ans-phi[j]*r[j][0]%Mod*c[j][0]%Mod+Mod+Mod)%Mod;
                    r[j][0]=(r[j][0]-r[j][x/j]+Mod+Mod)%Mod;
                    (r[j][x/j]*=y)%=Mod;
                    r[j][0]=(r[j][0]+r[j][x/j])%Mod;
                    ans=(ans+phi[j]*r[j][0]%Mod*c[j][0]%Mod+Mod+Mod)%Mod;
                }
                if(j*j!=x&&x%j==0){
                    ans=(ans-phi[x/j]*r[x/j][0]%Mod*c[x/j][0]%Mod+Mod+Mod)%Mod;
                    r[x/j][0]=(r[x/j][0]-r[x/j][j]+Mod+Mod)%Mod;
                    (r[x/j][j]*=y)%=Mod;
                    r[x/j][0]=(r[x/j][0]+r[x/j][j])%Mod;
                    ans=(ans+phi[x/j]*r[x/j][0]%Mod*c[x/j][0]%Mod+Mod+Mod)%Mod;
                }
            }
        }else{
            for(int j=1;j*j<=x;j++){
                if(x%j==0){
                    ans=(ans-phi[j]*r[j][0]%Mod*c[j][0]%Mod+Mod+Mod)%Mod;
                    c[j][0]=(c[j][0]-c[j][x/j]+Mod)%Mod;
                    (c[j][x/j]*=y)%=Mod;
                    c[j][0]=(c[j][0]+c[j][x/j])%Mod;
                    ans=(ans+phi[j]*r[j][0]%Mod*c[j][0]%Mod+Mod+Mod)%Mod;
                }
                if(j*j!=x&&x%j==0){
                    ans=(ans-phi[x/j]*r[x/j][0]%Mod*c[x/j][0]%Mod+Mod+Mod)%Mod;
                    c[x/j][0]=(c[x/j][0]-c[x/j][j]+Mod)%Mod;
                    (c[x/j][j]*=y)%=Mod;
                    c[x/j][0]=(c[x/j][0]+c[x/j][j])%Mod;
                    ans=(ans+phi[x/j]*r[x/j][0]%Mod*c[x/j][0]%Mod+Mod+Mod)%Mod;
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}