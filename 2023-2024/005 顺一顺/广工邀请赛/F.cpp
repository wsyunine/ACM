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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,v;
int x[N],cnt[N],s[N],num[N],sum=0;
int p[N];
map<int,int> mapp,mapp2;
int dp[N];

bool cmp(int x,int y){
    return num[x]<num[y];
}

int main(){

    read(t);
    while(t--){
        read(n),read(v);sum=0;
        mapp.clear(),mapp2.clear();
        for(int i=1;i<=n;i++) cnt[i]=0,dp[i]=0;
        for(int i=1;i<=n;i++){
            read(x[i]);
            if(!mapp[x[i]]) mapp[x[i]]=++sum,num[sum]=x[i];
            cnt[mapp[x[i]]]++;
        }
        for(int i=1;i<=sum;i++) p[i]=i;
        sort(p+1,p+1+sum,cmp);

        for(int i=1;i<=sum;){
            int st=i;
            if(mapp2[(num[p[i]])%v]) dp[i]=mapp2[(num[p[i]])%v]+cnt[p[i]];
            dp[i]=max(dp[i],cnt[p[i]]);
            i++;
            while(i<=sum&&num[p[i]]==num[p[i-1]]+1){
                if(mapp2[(num[p[i]])%v]) dp[i]=mapp2[(num[p[i]])%v]+cnt[p[i]];
                dp[i]=max(dp[i],dp[i-1]+cnt[p[i]]);
                i++;
            }
            
            for(int j=st;j<i;j++){
                mapp2[(num[p[j]])%v]=0;
            }
            if(mapp2[(num[p[i-1]]+1)%v]) mapp2[(num[p[i-1]]+1)%v]=max(dp[i-1],mapp2[(num[p[i-1]]+1)%v]);
            else mapp2[(num[p[i-1]]+1)%v]=dp[i-1];
        }

        int ans=0;
        for(int i=1;i<=sum;i++) ans=max(ans,dp[i]);

        cout<<n-ans<<endl;
        
    }

    return 0;
}