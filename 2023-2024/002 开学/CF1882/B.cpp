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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

// int t;
// int n;
// int vis[N];
// vector<vector<int> > s(51);

int t;
int n;
vector<vector<int> > s(51);
int vis[N],num[N];

int main(){

    // read(t);
    // while(t--){
    //     read(n);
    //     int minn=100;
    //     int num=0;
    //     for(int i=1;i<51;i++) vis[i]=0,s[i].clear();
    //     for(int i=1;i<=n;i++){
    //         int x,y;
    //         read(x);
    //         for(int j=1;j<=x;j++){
    //             read(y);
    //             if(s[y].size()==0) num++;
    //             s[y].push_back(i);
    //         }
    //     }

    //     for(int i=1;i<=50;i++) if(s[i].size()!=0) minn=min(minn,(int)s[i].size());

    //     vector<int> cnt;

    //     for(int i=1;i<51;i++){
    //         if(s[i].size()==minn) cnt.push_back(i);
    //     }

    //     int m=cnt.size();
    //     int ansx,ans=m;
    //     // cout<<m<<endl;
    //     for(int i=0;i<m;i++){
    //         for(auto j:s[cnt[i]]){
    //             vis[j]=1;
    //         }
    //         ansx=1;
    //         for(int j=0;j<m;j++){
    //             if(i==j) continue;
    //             bool idea=0;
    //             for(auto k:s[cnt[j]]) if(!vis[k]) idea=1;
    //             if(!idea) ansx++;
    //         }
    //         for(auto j:s[cnt[i]]){
    //             vis[j]=0;
    //         }
    //         // cout<<cnt[i]<<" "<<ansx<<endl;
    //         ans=min(ans,ansx);
    //     }
    //     cout<<num-ans<<endl;
    // }

    read(t);
    while(t--){
        int n;
        read(n);
        int m=0;
        for(int j=1;j<=n;j++) vis[j]=0,s[j].clear();
        for(int j=1;j<=50;j++) num[j]=0;
        for(int i=1;i<=n;i++){
            int x;
            read(x);
            for(int j=1;j<=x;j++){
                int y;
                read(y);
                if(!num[y]) m++;
                num[y]=1;
                s[i].push_back(y);
            }
        }

        int ans=0,cnt=0;

        for(int i=1;i<=50;i++){
            for(int j=1;j<=n;j++) vis[j]=0;
            for(int j=1;j<=50;j++) num[j]=0;
            cnt=0;

            for(int j=1;j<=n;j++){
                if(find(s[j].begin(),s[j].end(),i)!=s[j].end()) vis[j]=1;
            }

            for(int j=1;j<=n;j++){
                if(vis[j]) continue;
                for(auto k:s[j]){
                    if(!num[k]) cnt++;
                    num[k]=1;
                }
            }

            // cout<<cnt<<endl;

            if(cnt!=m) ans=max(ans,cnt);
        }

        cout<<ans<<endl;
    }
    
    return 0;
}