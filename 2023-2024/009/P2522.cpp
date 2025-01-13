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

int n;
int a,b,c,d,k,res=0;
int miu[N],mindiv[N],pri[N],cnt=0;

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

int calc(int a,int b,int d){
    int ans=0;
    if(a<b) swap(a,b);
        int u=a/d,v=b/d;

        int pos=0,lu=1,ru=u/(u/lu),lv=1,rv=v/(v/lv);
        while(1){
            if(ru<rv){
                ans+=(u/lu)*(v/lv)*(miu[ru]-miu[pos]);
                pos=ru;
                lu=ru+1;
                if(lu>u) break;
                ru=u/(u/lu);
            }else if(ru>rv){
                ans+=(u/lu)*(v/lv)*(miu[rv]-miu[pos]);
                pos=rv;
                lv=rv+1;
                if(lv>v) break;
                rv=v/(v/lv);
            }else{
                ans+=(u/lu)*(v/lv)*(miu[ru]-miu[pos]);
                pos=ru;
                lu=ru+1;
                if(lu>u) break;
                ru=u/(u/lu);
                lv=rv+1;
                if(lv>v) break;
                rv=v/(v/lv);
            }
        }
        return ans;
}

signed main(){

    get_miu(50000);
    for(int i=1;i<=50000;i++) miu[i]+=miu[i-1];

    read(n);

    while(n--){
        read(a),read(c),read(b),read(d),read(k);res=0;

        res=calc(c,d,k)-calc(a-1,d,k)-calc(c,b-1,k)+calc(a-1,b-1,k);

        cout<<res<<endl;
    }

    return 0;
}