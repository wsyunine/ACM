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

int n,m;
int t[N][27],tag[N][27],tag0[N][27];
string s;

void pushup(int x,int opi){
    t[x][opi]=t[x<<1][opi]+t[x<<1|1][opi];
}

void build(int x,int l,int r){
    if(l==r){
        t[x][s[l-1]-'a'+1]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    for(int i=1;i<=26;i++) pushup(x,i);
}

void pushdown(int x,int l,int r,int opi){
    if(tag0[x][opi]){
        t[x<<1][opi]=0;
        t[x<<1|1][opi]=0;
        tag0[x<<1][opi]=1;
        tag0[x<<1|1][opi]=1;
        tag[x<<1][opi]=0;
        tag[x<<1|1][opi]=0;
        tag0[x][opi]=0;
    }
    if(tag[x][opi]){
        int mid=(l+r)>>1;
        t[x<<1][opi]+=tag[x][opi]*(mid-l+1);
        t[x<<1|1][opi]+=tag[x][opi]*(r-mid);
        tag[x<<1][opi]+=tag[x][opi];
        tag[x<<1|1][opi]+=tag[x][opi];
        tag[x][opi]=0;
    }
}

void change(int x,int l,int r,int cl,int cr,int opi,int v){
    if(cl<=l&&cr>=r){
        t[x][opi]+=v*(r-l+1);
        tag[x][opi]+=v;
        return;
    }
    pushdown(x,l,r,opi);
    int mid=(l+r)>>1;
    if(cl<=mid) change(x<<1,l,mid,cl,cr,opi,v);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr,opi,v);
    pushup(x,opi);
}

void change0(int x,int l,int r,int cl,int cr,int opi){
    if(cl<=l&&cr>=r){
        t[x][opi]=0;
        tag0[x][opi]=1;
        tag[x][opi]=0;
        return;
    }
    pushdown(x,l,r,opi);
    int mid=(l+r)>>1;
    if(cl<=mid) change0(x<<1,l,mid,cl,cr,opi);
    if(cr>mid) change0(x<<1|1,mid+1,r,cl,cr,opi);
    pushup(x,opi);
}

int query(int x,int l,int r,int ql,int qr,int opi){
    if(ql<=l&&qr>=r) return t[x][opi];
    pushdown(x,l,r,opi);
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) res+=query(x<<1,l,mid,ql,qr,opi);
    if(qr>mid) res+=query(x<<1|1,mid+1,r,ql,qr,opi);
    pushup(x,opi);
    return res;
}

int main(){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    read(n),read(m);
    cin>>s;

    build(1,1,n);
    
    for(int i=1;i<=m;i++){
        int l,r;
        vector<int> sum(28,0);
        // cout<<query(1,1,n,1,n,1)<<endl;
        read(l),read(r);
        if((r-l+1)%2){
            int sj=0,sz=0;
            for(int i=1;i<=26;i++){
                sum[i]=query(1,1,n,l,r,i);
                if(sum[i]%2) sj++,sz=i;
            }
            if(sj!=1) continue;
            for(int i=1;i<=26;i++) change0(1,1,n,l,r,i);
            int mid=(l+r)>>1;
            change(1,1,n,mid,mid,sz,1);
            sum[sz]--;
            for(int i=1,j=l,op=r;i<=26;i++){
                if(!sum[i]) continue;
                sum[i]/=2;
                change(1,1,n,j,j+sum[i]-1,i,1);
                change(1,1,n,op-sum[i]+1,op,i,1);
                j=j+sum[i];
                op=op-sum[i];
            }
        }else{
            int sj=0;
            for(int i=1;i<=26;i++){
                sum[i]=query(1,1,n,l,r,i);
                if(sum[i]%2) sj++;
            }
            if(sj!=0) continue;
            for(int i=1;i<=26;i++) change0(1,1,n,l,r,i);
            for(int i=1,j=l,op=r;i<=26;i++){
                if(!sum[i]) continue;
                sum[i]/=2;
                change(1,1,n,j,j+sum[i]-1,i,1);
                change(1,1,n,op-sum[i]+1,op,i,1);
                j=j+sum[i];
                op=op-sum[i];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            if(query(1,1,n,i,i,j)){
                cout<<(char)(j+'a'-1);
                break;
            }
        }
    }
    cout<<endl;

    return 0;
}
/*

7 2
abbacbc
3 7
1 5
z
*/