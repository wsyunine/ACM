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

int t;
int n;
int a[N],b[N],res=0,tmp=0;

bool check(int x){
    tmp=0;res=0;
    for(int i=1;i<=2*n;i++) b[i]=a[i];
    for(int i=2*n;i>=1;i--){
        tmp*=2;
        if(tmp) res++;
        if(b[i]<x){
            tmp+=(x-b[i]);
            b[i]=b[(i>n)?i-n:i+n]=x;
        }else if(b[i]>x){
            int op=b[i];
            b[i]=b[(i>n)?i-n:i+n]=op-min(tmp,op-x);
            tmp-=min(tmp,op-x);
        }
        if(tmp>2e14) return 1;
        //cout<<x<<" "<<tmp<<endl;
    }
    
    for(int i=1;i<=n;i++) if(b[i]!=x) return 0;
    return 1;
}

signed main(){

    read(t);
    while(t--){
        read(n);res=0;tmp=0;
        
        int mn=0x3f3f3f3f3f3f3f,mx=0;
        for(int i=1;i<=n;i++) read(a[i]),mn=min(mn,a[i]),mx=max(mx,a[i]);
        for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];

        int l=mn,r=mx;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }

        check(l);
        if(tmp){
            cout<<-1<<endl;
            continue;
        }

        int idea=1;
        res=0;
        for(int i=1;i<=2*n;i++){
            if(a[i]>l){
                if((a[i]-l)%2){cout<<-1<<endl;idea=0;break;}
                res+=(a[i]-l)/2;
                a[i+1]=a[(i+1)>n?(i+1-n):(i+1+n)]=a[i+1]+(a[i]-l)/2;
                a[i]=a[i>n?i-n:i+n]=l;
            }
            // for(int j=1;j<=2*n;j++) cout<<a[j]<<" ";
            // cout<<endl;
        }
        if(!idea) continue;
        cout<<res<<endl;

    }

    return 0;
}