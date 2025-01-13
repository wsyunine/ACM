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
int t;
int k;
int q;

signed main(){

    read(n),read(k),read(q);
    vector<vector<int>> mapp(n+10,vector<int>(k+10,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            read(mapp[i][j]);
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            mapp[i][j]=mapp[i-1][j]|mapp[i][j];
        }
    }

    for(int j=1;j<=k;j++) mapp[n+1][j]=0x3f3f3f3f3f3f3f3f;

    while(q--){
        int op;
        vector<pair<int,int>> dy,xy;
        read(op);
        for(int i=1;i<=op;i++){
            int c,d;
            char e;
            cin>>c>>e>>d;
            if(e=='<'){
                xy.push_back({c,d});
            }else{
                dy.push_back({c,d});
            }
        }
        int l=1,r=n+1;
        while(l<r){
            int mid=(l+r)>>1;
            bool idea=1;
            for(auto i:dy){
                if(mapp[mid][i.first]<=i.second) idea=0;
            }
            if(idea) r=mid;
            else l=mid+1;
        }
        if(!dy.size()) l=1;
        int ll=0,rr=n+1;
        while(ll<rr){
            int mid=(ll+rr+1)>>1;
            bool idea=1;
            for(auto i:xy){
                if(mapp[mid][i.first]>=i.second) idea=0;
            }
            if(idea) ll=mid;
            else rr=mid-1;
        }
        if(!xy.size()) ll=n;

        if(l<=ll&&l!=n+1&&ll!=0){
            cout<<l<<endl;
        }else cout<<-1<<endl;
    }

    return 0;
}