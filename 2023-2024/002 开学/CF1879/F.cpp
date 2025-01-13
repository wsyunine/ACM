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
#define N 400010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int mx=0;
ll ans[N];
int n,f1[30][N],f2[30][N],g[30][N],lg[N]={-1};
int a[N];

struct inp{
    int h,a;
    int num;
}p[N];

struct node{
    ll idx,k1,k2;
};

bool cmp(inp a,inp b){
    return a.a<b.a;
}

void init(){
    for(int i=1;i<=n;i++) f1[0][i]=p[i].h,f2[0][i]=0,lg[i]=lg[i/2]+1,g[0][i]=p[i].num;
    for(int i=1;i<=lg[n];i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            if(f1[i-1][j]<f1[i-1][j+(1<<(i-1))]){
                f1[i][j]=f1[i-1][j+(1<<(i-1))];
                g[i][j]=g[i-1][j+(1<<(i-1))];
                f2[i][j]=max(f1[i-1][j],f2[i-1][j+(1<<(i-1))]);
            }else if(f1[i-1][j]>f1[i-1][j+(1<<(i-1))]){
                f1[i][j]=f1[i-1][j];
                g[i][j]=g[i-1][j];
                f2[i][j]=max(f2[i-1][j],f1[i-1][j+(1<<(i-1))]);
            }else{
                f1[i][j]=f1[i-1][j];
                g[i][j]=-1;
                f2[i][j]=max(f2[i-1][j],f2[i-1][j+(1<<(i-1))]);
            }
        }
    }
}

node query(int l,int r){
    node ans;
    int len=lg[r-l+1];
    if(f1[len][l]>f1[len][r-(1<<len)+1]){
        ans.k1=f1[len][l];
        ans.idx=g[len][l];
        ans.k2=max(f1[len][r-(1<<len)+1],f2[len][l]);
    }else if(f1[len][l]<f1[len][r-(1<<len)+1]){
        ans.k1=f1[len][r-(1<<len)+1];
        ans.idx=g[len][r-(1<<len)+1];
        ans.k2=max(f2[len][r-(1<<len)+1],f1[len][l]);
    }else{
        ans.k1=f1[len][l];
        ans.k2=max(f2[len][l],f2[len][r-(1<<len)+1]);
        if(g[len][l]==g[len][r-(1<<len)+1]) ans.idx=g[len][l];
        else ans.idx=-1;
    }
    return ans;
}

int main(){

    read(t);
    while(t--){
        read(n);mx=0;
        for(int i=1;i<=n;i++) read(p[i].h),p[i].num=i,ans[i]=0;
        for(int i=1;i<=n;i++) read(p[i].a),mx=max(mx,p[i].a);

        sort(p+1,p+1+n,cmp);

        for(int i=1;i<=n;i++) a[i]=p[i].a;

        init();

        for(int i=1;i<=mx;i++){
            node tmp,ad;
            ad.idx=0,ad.k1=0,ad.k2=0;
            // cout<<i<<" "<<ceil((1.0*mx)/(1.0*i))<<endl;
            for(int c=1;c<=ceil((1.0*mx)/(1.0*i));c++){
                int l=lower_bound(a+1,a+n+1,i*(c-1)+1)-a;
                int r=upper_bound(a+1,a+n+1,i*c)-a-1;
                // cout<<i*(c-1)+1<<" "<<i*c<<" "<<l<<" "<<r<<endl;
                if(l>r) continue;
                tmp=query(l,r);
                // cout<<l<<" "<<r<<" "<<tmp.k1<<" "<<tmp.idx<<" "<<tmp.k2<<endl;
                if(tmp.k1*c>ad.k1){
                    ad.k2=max(ad.k1,tmp.k2*c);
                    ad.k1=tmp.k1*c;
                    ad.idx=tmp.idx;
                }else if(tmp.k1*c<ad.k1){
                    ad.k2=max(ad.k2,tmp.k1*c);
                }else{
                    ad.idx=-1;
                    ad.k2=max(ad.k2,tmp.k2*c);
                }
            }
            // cout<<ad.k1<<" "<<ad.idx<<" "<<ad.k2<<endl;
            if(ad.idx==-1) continue;
            ans[ad.idx]=max(ans[ad.idx],ad.k1-ad.k2);
        }

        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    

    return 0;
}