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

int n;
int q;
string s;

int t[N],pre1[N],suf2[N],res[N];

void pushup(int x){
    t[x]=max(t[x<<1],t[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return t[x]=res[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(qr<ql) return 0;
    if(l>=ql&&r<=qr) return t[x];
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) res=max(res,query(x<<1,l,mid,ql,qr));
    if(qr>mid) res=max(res,query(x<<1|1,mid+1,r,ql,qr));
    return res;
}

int main(){

    read(n),read(q);
    cin>>s;
    s=' '+s;

    vector<int> xg;
    for(int i=1;i<=n;i++){
        if(s[i]=='/') xg.push_back(i);
    }

    for(int i=1;i<=n;i++){
        if(s[i]=='1') pre1[i]=pre1[i-1]+1;
        else pre1[i]=0;
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='2') suf2[i]=suf2[i+1]+1;
        else suf2[i]=0;
    }

    for(int i=1;i<=n;i++){
        if(s[i]=='/') res[i]=min(pre1[i-1],suf2[i+1]);
    }

    build(1,1,n);

    while(q--){
        int l,r,ans=0;
        read(l),read(r);

        int ll=*lower_bound(xg.begin(),xg.end(),l);
        int rr=*(upper_bound(xg.begin(),xg.end(),r)--);

        if(ll>rr){
            cout<<0<<endl;
            continue;
        }

        ans=max(ans,min(min(ll-1-l+1,r-ll),res[ll])*2+1);
        ans=max(ans,min(min(r-(rr+1)+1,rr-l),res[rr])*2+1);
        ans=max(ans,query(1,1,n,ll+1,rr-1));

        cout<<ans<<endl;
    }

    return 0;
}