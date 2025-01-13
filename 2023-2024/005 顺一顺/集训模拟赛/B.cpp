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
#define N 800010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int len,n;
int p[N];
pair<int,int> sp[N];
char str[N],s[N];
int tr[N];

void pushup(int x){
    tr[x]=max(tr[x<<1],tr[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r){tr[x]=p[l];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int query1(int x,int l,int r,int ql,int qr,int v){
    if(l==r){return tr[x]>=v?l:0;}
    int mid=(l+r)>>1;
    if(ql<=l&&qr>=r){
        if(tr[x<<1]>=v) return query1(x<<1,l,mid,ql,qr,v);
        else if(tr[x<<1|1]>=v) return query1(x<<1|1,mid+1,r,ql,qr,v);
        else return 0;
    }
    int res=0;
    if(ql<=mid) res=query1(x<<1,l,mid,ql,qr,v);
    if(res) return res;
    if(qr>mid) res=query1(x<<1|1,mid+1,r,ql,qr,v);
    return res;
}

int query2(int x,int l,int r,int ql,int qr,int v){
    if(l==r){return tr[x]>=v?l:0;}
    int mid=(l+r)>>1;
    if(ql<=l&&qr>=r){
        if(tr[x<<1|1]>=v) return query2(x<<1|1,mid+1,r,ql,qr,v);
        else if(tr[x<<1]>=v) return query2(x<<1,l,mid,ql,qr,v);
        else return 0;
    }
    int res=0;
    if(qr>mid) res=query2(x<<1|1,mid+1,r,ql,qr,v);
    if(res) return res;
    if(ql<=mid) res=query2(x<<1,l,mid,ql,qr,v);
    return res;
}

int main(){

    read(t);
    while(t--){
        scanf("%s",str+1);
        len=strlen(str+1);
        memset(p,0,sizeof p);
        memset(tr,0,sizeof tr);
        n=0;
        s[0]='~';
        for(int i=1;i<=len;i++) s[++n]='#',s[++n]=str[i];
        s[++n]='#';
        
        int mid=0,r=0;
        for(int i=1;i<=n;i++){
            if(i<r) p[i]=min(p[(mid<<1)-i],r-i+1);
            while(s[i+p[i]]==s[i-p[i]]) p[i]++;
            if(i+p[i]-1>r) r=i+p[i]-1,mid=i;
        }

        for(int i=2;i<=n;i+=2) p[i]=0;

        // for(int i=1;i<=n;i++) cout<<p[i]<<" ";
        // cout<<endl;

        build(1,1,n);

        int ans=0;
        int po1=0,po2=0;
        for(int i=1;i<=n;i+=2){
            if(p[i]==1) continue;
            po1=query1(1,1,n,i-p[i]+1,i-1,p[i]);
            po2=query2(1,1,n,i+1,i+p[i]-1,p[i]);
            if(po1) ans=max(ans,i-po1+1);
            if(po2) ans=max(ans,po2-i+1);
        }

        ans=(ans-1)/2;
        cout<<ans*3<<endl;

    }

    return 0;
}