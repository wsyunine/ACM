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
#define N 200010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int sta[N];
pair<int,int> d[N],s[N];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first==b.first?a.second<b.second:a.first<b.first;
}

int sqr(int x){return x*x;}

int dis(int x,int y){
    return sqr(d[x].first-d[y].first)+sqr(d[x].second-d[y].second);
}

void merge(int l,int r){
    int mid=(l+r)>>1,t1=l,t2=mid+1;
    for(int i=l;i<=r;i++){
        if(t1<=mid&&(t2>r||d[t1].second<d[t2].second)) s[i]=d[t1++];
        else s[i]=d[t2++];
    }
    for(int i=l;i<=r;i++) d[i]=s[i];
}

int solve(int l,int r){
    if(l>=r) return 0x3f3f3f3f3f3f3f;
    if(l+1==r){
        d[l].second>d[r].second?swap(d[l],d[r]),void():void();
        // if(dis(l,r)==0) cout<<l<<" "<<r<<endl;
        return dis(l,r);
    }
    int mid=(l+r)>>1,t=d[mid].first;
    int top=0;
    int a=solve(l,mid),b=solve(mid+1,r);
    int ds=min(a,b);
    merge(l,r);
    for(int i=l;i<=r;i++){
        if(sqr(d[i].first-t)<ds) sta[++top]=i;
    }
    for(int i=1;i<=top;i++){
        for(int j=i+1;j<=top&&sqr(d[sta[j]].second-d[sta[i]].second)<ds;j++){
            ds=min(ds,dis(sta[j],sta[i]));
        }
    }
    // if(ds==0) cout<<l<<" "<<r<<endl;
    return ds;
}

signed main(){

    // freopen("P1429.in","r",stdin);

    int n;

    read(n);

    for(int i=1;i<=n;i++) read(d[i].first),read(d[i].second);

    sort(d+1,d+n+1,cmp);

    cout<<fixed<<setprecision(4)<<sqrt(solve(1,n))<<endl;

    return 0;
}