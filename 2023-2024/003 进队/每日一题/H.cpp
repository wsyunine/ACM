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
#define N 900010
#define INF 1e13
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

struct query{
    int u,v;
}op[N];

ll n,q,a[310];
bool mapp[310][310];
int ans1[310][310];
ll ans2[310][310];

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++) (s[j]=='Y')?mapp[i][j+1]=1:mapp[i][j+1]=0;
    }

    read(q);

    for(int i=1;i<=q;i++){
        read(op[i].u),read(op[i].v);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mapp[i][j]) ans1[i][j]=1,ans2[i][j]=a[i]+a[j];
            else if(i==j) ans1[i][j]=0,ans2[i][j]=a[i];
            else ans1[i][j]=0x3f3f3f3f;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(k==i||k==j) continue;
                if(ans1[i][k]+ans1[k][j]<ans1[i][j]){
                    ans1[i][j]=ans1[i][k]+ans1[k][j];
                    ans2[i][j]=ans2[i][k]+ans2[k][j]-a[k];
                }else if(ans1[i][k]+ans1[k][j]==ans1[i][j]){
                    if(ans2[i][j]>=ans2[i][k]+ans2[k][j]-a[k]) continue;
                    ans2[i][j]=ans2[i][k]+ans2[k][j]-a[k];
                }
            }
        }
    }

    for(int i=1;i<=q;i++){
        if(ans1[op[i].u][op[i].v]==0x3f3f3f3f) cout<<"Impossible"<<endl;
        else cout<<ans1[op[i].u][op[i].v]<<" "<<ans2[op[i].u][op[i].v]<<endl;
    }

    return 0;
}