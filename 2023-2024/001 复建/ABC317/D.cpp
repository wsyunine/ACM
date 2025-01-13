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
using namespace std;
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

struct node{
    int z;
    int cc;
}s[110];

bool cmp(node a,node b){
    return a.cc==b.cc?(a.z<b.z):a.cc<b.cc;
}

int main(){

    int n,sz=0,st=0,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sz+=c;
        if(a>b) st+=c;
        else{
            s[++m].cc=((a+b+1)/2)-a;
            s[m].z=c;
        }
    }
    sz=(sz+1)/2;
    sort(s+1,s+1+m,cmp);

    int v=sz-st;
    if(v<=0){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int> > dp(m+1,vector<int>(2*v+2,1e8));

    int ans=1e8;
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=s[i].z;j<=2*v;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j-s[i].z]+s[i].cc);
            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            if(j>=v) ans=min(ans,dp[i][j]);
        }
    }

    cout<<ans<<endl;

    return 0;
}