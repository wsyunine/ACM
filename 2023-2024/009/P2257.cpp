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
#define N 10000010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a,b;
ll ans=0;
int miu[N],mindiv[N],pri[N],cnt=0;
ll s[N];

void get_miu(int x){
    miu[1]=1;
    for(int i=2;i<=x;i++){
        if(!mindiv[i]) mindiv[i]=pri[++cnt]=i,miu[i]=-1;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||i*pri[j]>x) break;
            mindiv[i*pri[j]]=pri[j];
            miu[i*pri[j]]=(i%pri[j])?(-miu[i]):0;
        }
    }
}

int main(){

    get_miu(10000000);

    for(int i=1;i<=cnt;i++){
        for(int j=1;j*pri[i]<=10000000;j++){
            s[j*pri[i]]+=miu[j];
        }
    }
    for(int i=1;i<=10000000;i++) s[i]+=s[i-1];

    read(n);

    while(n--){
        read(a),read(b);ans=0;

        ll pos=0,la=1,ra=a/(a/la),lb=1,rb=b/(b/lb);
        while(1){
            if(ra<rb){
                ans+=(a/la)*(b/lb)*(s[ra]-s[pos]);
                pos=ra;
                la=ra+1;
                if(la>a) break;
                ra=a/(a/la);
            }else if(ra>rb){
                ans+=(a/la)*(b/lb)*(s[rb]-s[pos]);
                pos=rb;
                lb=rb+1;
                if(lb>b) break;
                rb=b/(b/lb);
            }else{
                ans+=(a/la)*(b/lb)*(s[ra]-s[pos]);
                pos=ra;
                la=ra+1;
                if(la>a) break;
                ra=a/(a/la);
                lb=rb+1;
                if(lb>b) break;
                rb=b/(b/lb);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}