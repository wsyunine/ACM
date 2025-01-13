//Miller-Rabin
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,t;

int abss(int x){
    if(x<0) return -x;
    return x;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int fmul(int a,int b,int p){
    int res=0;a%=p;
    for(;b;b>>=1,a=(a+a)%p) if(b&1) res=(res+a)%p;
    return res;
}

int fpow(int a,int b,int p){
    int res=1;a%=p;
    for(;b;b>>=1,a=fmul(a,a,p)) if(b&1) res=fmul(res,a,p);
    return res;
}

bool check(int a,int b,int p){
    int s=fpow(a,b,p);
    if(s==p-1) return 1;
    if(s==1) return b&1?1:check(a,b/2,p);
    return 0;
}

bool Miller_Rabin(int x){
    if(x<=1) return 0;
    if(x<=3) return 1;
    if((x&1)==0||x%3==0) return 0; 
    static int p[]={2,3,5,7,11,13,17,19};
    for(int i=0;i<8;i++){
        if(x==p[i]) return 1;
        else if(!check(p[i],x-1,x)) return 0;
    }
    return 1;
}

int Pollard_Rho(int x,int c){
    int i=1,k=2;
    int t1=rand()%x;
    int t2=t1;
    while(1){
        i++;
        t1=(fmul(t1,t1,x)+c)%x;
        int d=gcd(abss(t2-t1),x);
        if(d!=1&&d!=x) return d;
        if(t2==t1) return x;
        if(i==k) t2=t1,k<<=1;
    }
}

vector<int> q;
void max_fac(int x){
    if(Miller_Rabin(x)){q.push_back(x);return;}
    int p=x;
    while(p>=x) p=Pollard_Rho(p,rand()%(x-1)+1);
    max_fac(p);
    max_fac(x/p);
}

signed main(){

    read(t);
    while(t--){
        read(n);q.clear();
        if(Miller_Rabin(n)){
            cout<<"Prime"<<endl;
        }else{
            max_fac(n);
            sort(q.begin(),q.end());
            cout<<q[0]<<endl;
        }
    }

    return 0;
}
//124131412412451
