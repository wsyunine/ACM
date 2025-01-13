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

int T,n,m;
int b[N],e[N],s[N],t[N];

signed main(){

    read(T);
    while(T--){
        read(n),read(m);
        vector<pair<int,int>> ts;
        s[m+1]=1e9+1;
        for(int i=1;i<=n;i++) read(b[i]),read(e[i]);
        for(int i=1;i<=m;i++) read(s[i]),read(t[i]);
        for(int i=1;i<=m;i++){
            ts.push_back({s[i],t[i]});
            int l=t[i],r=t[i]+2*(t[i]-s[i]);
            if(r<s[i+1]) ts.push_back({r,s[i+1]});
        }
        sort(ts.begin(),ts.end());
        int pos=0,id=1,r=0;
        for(int i=1;i<=n;i++){
            if(r>b[i]) id=0;
            while(pos<ts.size()&&ts[pos].first<e[i]){
                if(ts[pos].second>b[i]) id=0;
                r=max(r,ts[pos].second);
                pos++;
            }
        }
        if(id) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}