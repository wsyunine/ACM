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
string s;
int prex[N],pred[N];
int sumx[N],sumd[N];
int ans[N];

signed main(){

    read(t);
    while(t--){
        read(n);
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n;i++){
            prex[i]=prex[i-1];
            pred[i]=pred[i-1];
            sumx[i]=sumx[i-1];
            sumd[i]=sumd[i-1];
            if(s[i]=='<') prex[i]++,sumx[i]+=i;
            else if(s[i]=='>') pred[i]++,sumd[i]+=i;
        }

        int xx=0,dd=0;
        for(int i=1;i<=n;i++){
            int ll=0,rr=0,pot=0;
            if(s[i]=='<'){
                ll=dd;
                rr=prex[n]-prex[i-1];
                if(ll>=rr){
                    pot=upper_bound(pred+1,pred+1+n,dd-rr)-pred;
                    ans[i]=n+1+i+(sumx[n]-sumx[i])*2-(sumd[i]-sumd[pot-1])*2;
                }else{
                    pot=upper_bound(prex+1,prex+1+n,xx+ll)-prex;
                    ans[i]=i+(sumx[pot]-sumx[i])*2-(sumd[i])*2;
                }
                xx++;
            }else{
                dd++;
                ll=dd;
                rr=prex[n]-prex[i];
                if(rr>=ll){
                    pot=lower_bound(prex+1,prex+1+n,xx+ll)-prex;
                    ans[i]=-i+(sumx[pot]-sumx[i])*2-(sumd[i-1])*2;
                }else{
                    pot=lower_bound(pred+1,pred+1+n,dd-rr)-pred;
                    ans[i]=1-i+n+(sumx[n]-sumx[i])*2-(sumd[i-1]-sumd[pot-1])*2;
                }
            }
            // cout<<ll<<" "<<rr<<" "<<pot<<endl;
        }

        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}