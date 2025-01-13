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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int T;
int n,m,k;
long long mx=0;
long long h[N],x[N];

bool check(int s){
    vector<pair<int,int>> op;
    for(int i=1;i<=n;i++){
        int ll,rr;
        int u=(h[i]-1)/s+1;
        if(u>m) continue;
        ll=max(1ll,x[i]-(m-u));
        rr=x[i]+(m-u)+1;
        op.push_back({ll,1});
        op.push_back({rr,-1});
    }

    sort(op.begin(),op.end());

    int tmp=0;
    for(auto i:op){
        tmp+=i.second;
        if(tmp>=k) return 1;
    }
    return 0;
}

int main(){

    read(T);
    while(T--){
        read(n),read(m),read(k);mx=0;

        for(int i=1;i<=n;i++) read(h[i]),mx=max(mx,h[i]);
        for(int i=1;i<=n;i++) read(x[i]);

        int l=1,r=mx+1;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }

        if(l!=mx+1) cout<<l<<endl;
        else cout<<-1<<endl;

    }

    return 0;
}