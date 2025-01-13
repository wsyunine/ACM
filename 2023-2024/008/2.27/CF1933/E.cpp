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

int t;
int n,a[N],s[N],q;

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
        read(q);
        for(int i=1;i<=q;i++){
            int ll,l,u,r=n;
            read(ll),read(u);
            l=ll;
            while(l<r){
                int mid=(l+r)>>1;
                if(s[mid]-s[ll-1]-u>=0) r=mid;
                else l=mid+1;
            }
            if(l>ll&&abs(s[l-1]-s[ll-1]-u)<abs(s[l]-s[ll-1]-u)) l=l-1;
            cout<<l<<" ";
        }
        cout<<endl;
    }

    return 0;
}