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
#define N 2000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
int e[N],ne[N],idx,h[N],d[N],st,mxd,dd[N],res=0;
vector<int> sta;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x,int fa){
    d[x]=d[fa]+1;dd[x]=0;
    if(d[x]>d[st]) st=x;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        dd[x]++;
        if(j==fa) continue;
        dfs(j,x);
    }
}

void dfs1(int x,int fa){
    sta.push_back(x);
    d[x]=d[fa]+1;
    if(d[x]>mxd){
        if(sta.size()==3){
            if(dd[sta[1]]==2) res=1;
            else res=0;
        }else if(sta.size()==4){
            if(dd[sta[2]]==2||dd[sta[1]]==2) res=1;
            else res=0;
        }else if(sta.size()==5){
            if(dd[sta[2]]==2) res=1;
            else res=0;
        }else if(sta.size()==6){
            if(dd[sta[2]]==2&&dd[sta[3]]==2) res=1;
            else res=0;
        }else if(sta.size()==7){
            if(dd[sta[2]]==2&&dd[sta[3]]==2&&dd[sta[4]]==2) res=1;
            else res=0;
        }else res=0;
        mxd=d[x];
    }
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
    }
    sta.pop_back();
}

int main(){

    read(t);
    while(t--){
        read(n);mxd=0;res=0;d[0]=0;
        sta.clear();
        for(int i=1;i<=n;i++) h[i]=-1;
        idx=0;st=0;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
        }

        dfs(1,0);
        dfs1(st,0);
        // for(int i=1;i<=n;i++) cout<<dd[i]<<endl;

        if(res) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}