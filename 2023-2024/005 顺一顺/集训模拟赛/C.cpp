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
#include<unordered_map>
using namespace std;
#define N 500010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const int Mod=998244353;
int t;
int n,m,k;
int a[N];
int e[N],ne[N],idx,h[N];
int d[N];
int f[1010][40010];
unordered_map<int,int> mapp;
vector<int> numm;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){

    read(t);
    while(t--){
        idx=0;
        read(n),read(m),read(k);
        memset(f,0,sizeof f);
        mapp.clear();
        for(int i=1;i<=n;i++) read(a[i]),h[i]=-1,d[i]=0;
        for(int i=1;i<=m;i++){
            int a,b;
            read(a),read(b);
            add(a,b);d[b]++;
        }

        queue<int> q;
        vector<int> topo;
        topo.push_back(0);
        for(int i=1;i<=n;i++) if(!d[i]) q.push(i);
        while(!q.empty()){
            int s=q.front();
            q.pop();
            topo.push_back(s);
            for(int i=h[s];~i;i=ne[i]){
                int j=e[i];
                d[j]--;
                if(!d[j]) q.push(j);
            }
        }
        // for(int i=1;i<=n;i++) cout<<topo[i]<<" ";
        // cout<<endl;

        int cnt=1;
        numm.clear();
        numm.push_back(0);
        for(int l=1,r;l<=k;cnt++,l=r+1){
            r=k/(k/l);
            numm.push_back(k/l);
            mapp[k/l]=cnt;
        }

        for(int i=1;i<=n;i++){
            int ii=topo[i];
            if(a[ii]<=k) f[ii][mapp[k/a[ii]]]=1;
        }

        for(int i=1;i<=n;i++){
            int ii=topo[i];
            for(int j=h[ii];~j;j=ne[j]){
                int po=e[j];
                for(int op=1;op<=cnt;op++){
                    int kop=numm[op];
                    // (f[po][mapp[kop/a[po]]]+=f[ii][mapp[kop]]);
                }
            }
        }

        ll res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=cnt;j++) (res+=f[i][j])%=Mod;
        }
        cout<<res<<endl;
    }

    return 0;
}