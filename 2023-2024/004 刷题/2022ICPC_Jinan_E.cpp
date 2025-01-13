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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,k,p,q;

int exgcd(int &x,int &y,int a,int b){
    if(b==0){x=1,y=0;return a;}
    int g=exgcd(y,x,b,a%b);
    y-=(a/b)*x;
    return g;
}

int main(){

    read(t);
    while(t--){
        read(n),read(k);
        int a,b,x,y;

        a=n/k+1,b=n/k;
        p=n%k,q=k-p;
        int g=exgcd(x,y,a,b);
        if((n/2)%g!=0){cout<<"No"<<endl;continue;}

        x*=(n/2)/g;
        y*=(n/2)/g;
        
        int l1=-x/b,l2=(y-q)/a;
        if(l1*b+x<0) l1++;
        if(y-l2*a>q) l2++;
        int r1=(p-x)/b,r2=y/a;
        if(r1*b+x>p) r1--;
        if(y-r2*a<0) r2--;
        // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        if(max(l1,l2)<=min(r1,r2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}