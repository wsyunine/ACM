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
#define N 1500010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const ll Mod=1e9+7;

int n;
int t;
int r,c,idea=1;

int e[N],ne[N],idx,h[N],w[N],vis[N];

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

void dfs(int x,int fa){
    //cout<<idea<<endl;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        //if(j==fa) continue;
        if(vis[j]){
            if(w[i]==0&&vis[j]!=vis[x]) idea=0;
            if(w[i]==1&&vis[j]==vis[x]) idea=0;
        }
        //cout<<w[i]<<" "<<vis[x]<<" "<<vis[j]<<" "<<idea<<endl;
        if(j==fa||vis[j]) continue;
        if(w[i]) vis[j]=-vis[x];
        else vis[j]=vis[x];
        dfs(j,x);
    }
}

int main(){

    read(t);
    while(t--){
        read(r),read(c);idx=0;
        ll res=1;
        vector<vector<int>> mapp(r+1,vector<int>(c+1,0));
        for(int i=1;i<=r;i++){
            string str;
            cin>>str;h[i]=-1;vis[i]=0;
            for(int j=1;j<=c;j++){
                mapp[i][j]=str[j-1]=='0'?0:1;
            }
        }
        
        idea=1;

        if(c%2){
            int sum=0;
            for(int i=1;i<=r;i++){
                if(mapp[i][c/2+1]) sum++;
            }
            if(sum>1) idea=0;
        }

        for(int i=1;i<=c/2;i++){
            vector<int> le,re;
            for(int j=1;j<=r;j++){
                if(mapp[j][i]) le.push_back(j);
                if(mapp[j][c+1-i]) re.push_back(j);
            }
            if(le.size()+re.size()>2) idea=0;

            if(le.size()==2){
                add(le[0],le[1],1);
                add(le[1],le[0],1);
            }else if(re.size()==2){
                add(re[0],re[1],1);
                add(re[1],re[0],1);
            }else if(le.size()==1&&re.size()==1&&le[0]!=re[0]){
                add(le[0],re[0],0);
                add(re[0],le[0],0);
            }

            // if(le.size()==2){
            //     if(vis[le[0]]==0&&vis[le[1]]==0){
            //         if(!res) res=2;
            //         else (res*=2)%=Mod;
            //         vis[le[0]]=1;
            //         vis[le[1]]=-1;
            //     }else if(vis[le[0]]==0){
            //         vis[le[1]]=-vis[le[0]];
            //     }else if(vis[le[1]]==0){
            //         vis[le[0]]=-vis[le[1]];
            //     }else if(vis[le[0]]+vis[le[1]]) idea=0;
            // }
            // if(re.size()==2){
            //     if(vis[re[0]]==0&&vis[re[1]]==0){
            //         if(!res) res=2;
            //         else (res*=2)%=Mod;
            //         vis[re[0]]=1;
            //         vis[re[1]]=-1;
            //     }else if(vis[re[0]]==0){
            //         vis[re[1]]=-vis[re[0]];
            //     }else if(vis[re[1]]==0){
            //         vis[re[0]]=-vis[re[1]];
            //     }else if(vis[re[0]]+vis[re[1]]) idea=0;
            // }
            // if(re.size()==1&&le.size()==1){
            //     if(vis[re[0]]==0&&vis[le[0]]==0){
            //         if(!res) res=2;
            //         else (res*=2)%=Mod;
            //         vis[re[0]]=1;
            //         vis[le[0]]=-1;
            //     }else if(vis[re[0]]==0){
            //         vis[le[0]]=-vis[re[0]];
            //     }else if(vis[le[0]]==0){
            //         vis[re[0]]=-vis[le[0]];
            //     }else if(vis[re[0]]!=vis[le[0]]) idea=0;
            // }
            // if(re.size()==1&&le.size()==1&&re[0]==le[0]){
            //     if(vis[re[0]]==0){
            //         if(!res) res=2;
            //         else (res*=2)%=Mod;
            //         vis[re[0]]=1;
            //     }else{

            //     }
            // }
            // if(re.size()==1&&le.size()==1){
            //     if(vis[re[0]]==0&&vis[le[0]]==0){
            //         if(!res) res=2;
            //         else (res*=2)%=Mod;
            //         vis[re[0]]=1;
            //         vis[le[0]]=-1;
            //     }else if(vis[re[0]]==0){
            //         vis[le[0]]=-vis[re[0]];
            //     }else if(vis[le[0]]==0){
            //         vis[re[0]]=-vis[le[0]];
            //     }else if(vis[re[0]]!=vis[le[0]]) idea=0;
            // }
        }

        for(int i=1;i<=r;i++){
            if(!vis[i]) vis[i]=1,dfs(i,0),(res*=2ll)%=Mod;
        }

        if(!idea) cout<<0<<endl;
        else cout<<res<<endl;

    }

    return 0;
}