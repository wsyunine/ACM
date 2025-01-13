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

int n,k;
int a[N],c[N],s[N];
int q;

int main(){

    read(n),read(k);

    s[0]=0;
    for(int i=1;i<=n;i++) read(a[i]),i>k?s[i]=s[i-k]+a[i]:s[i]=a[i];

    // for(int i=1;i<=n;i++) cout<<s[i]<<" ";
    // cout<<endl;

    read(q);
    for(int i=1;i<=q;i++){
        int l,r,idea=1;
        read(l),read(r);
        for(int j=0;j<k;j++){
            int ql=l,qr=r;
            while(ql%k!=j) ql++;
            while(qr%k!=j) qr--;
            if(ql>k) c[j]=s[qr]-s[ql-k];
            else c[j]=s[qr];
        }
        for(int j=0;j<k;j++){
            if(c[j]!=c[0]) idea=0;
        }
        if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}