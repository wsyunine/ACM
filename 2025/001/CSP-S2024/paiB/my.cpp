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

int T;
int n,m,L,V;
int d[N],v[N],a[N],p[N];
int res1,res2;
vector<pair<int,int>> qj;

void solve(){
    res1=res2=0;
    qj.clear();
    read(n),read(m),read(L),read(V);
    for(int i=1;i<=n;i++) read(d[i]),read(v[i]),read(a[i]);
    for(int i=1;i<=m;i++) read(p[i]);
    p[0]=-1;p[m+1]=L+1;

    sort(p+1,p+1+m);

    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(d[i]<=p[m]){
                if(v[i]>V){
                    res1++;
                    int tmp=lower_bound(p+1,p+1+m,d[i])-p;
                    qj.push_back({m,tmp});
                }
            }
        }else if(a[i]<0){
            if(d[i]>p[m]) continue;
            if(v[i]<=V) continue;
            int l=1,r=m;
            while(l<r){
                int mid=(l+r+1)>>1;
                if((long long)v[i]*(long long)v[i]+2ll*(long long)a[i]*(long long)(p[mid]-d[i])>V*V) l=mid;
                else r=mid-1;
            }
            int tmp=lower_bound(p+1,p+1+m,d[i])-p;
            if((long long)v[i]*(long long)v[i]+2ll*(long long)a[i]*(long long)(p[tmp]-d[i])<=V*V) continue;
            if(tmp<=l) res1++,qj.push_back({l,tmp});
        }else if(a[i]>0){
            if(d[i]>p[m]) continue;
            int tmp=lower_bound(p+1,p+1+m,d[i])-p;
            int l=tmp,r=m+1;
            while(l<r){
                int mid=(l+r)>>1;
                if((long long)v[i]*(long long)v[i]+2ll*(long long)a[i]*(long long)(p[mid]-d[i])>V*V) r=mid;
                else l=mid+1;
            }
            if(l<=m) res1++,qj.push_back({m,l});
        }
    }
    printf("%d ",res1);

    sort(qj.begin(),qj.end());

    int pos=-1;
    for(auto i:qj){
        // cout<<i.second<<" "<<i.first<<endl;
        if(i.second>pos) res2++,pos=i.first;
    }
    printf("%d\n",m-res2);
}

int main(){

    freopen("data.in","r",stdin);
    freopen("res.out","w",stdout);

    read(T);
    while(T--){
        solve();
    }

    return 0;
}