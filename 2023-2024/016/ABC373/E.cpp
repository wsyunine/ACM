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
#define int long long 
#define ll long long 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int m;
ll k;
ll y;
int num[N];
ll a[N],b[N];
ll res[N];

bool cmp(ll x,ll y){
    return a[x]<a[y];
}

bool check(int p,ll x){
    int posr=upper_bound(b+1,b+1+n,b[p]+x)-b-1;
    int num=m-(n-posr);
    if(n-posr>=m) return 0;
    int posl=posr-num+1;
    //cout<<p<<" "<<x<<" "<<" "<<posl<<" "<<posr<<endl;
    if(posl<=p&&posr>=p){
        posl--;
        if(y-x+a[posr]-a[posl-1]-b[p]<(b[p]+x+1ll)*num) return 1;
        else return 0;
    }else{
        if(y-x+a[posr]-a[posl-1]<(b[p]+x+1ll)*num) return 1;
        else return 0;
    }
    return 0;
}

signed main(){

    read(n),read(m),read(k);
    for(int i=1;i<=n;i++) read(a[i]),num[i]=i;
    sort(num+1,num+n+1,cmp);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        a[i]=a[i-1]+a[i];
    }
    y=k-a[n];

    if(n==m){
        for(int i=1;i<=n;i++){
            cout<<0<<" ";
        }
        cout<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        int poss=upper_bound(b+1,b+1+n,b[i]+y)-b-1;
        if(n-poss>=m){res[num[i]]=-1;continue;}
        ll l=0,r=y;
        while(l<r){
            ll mid=(l+r)>>1;
            if(check(i,mid)) r=mid;
            else l=mid+1;
        }
        res[num[i]]=l;
    }

    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}