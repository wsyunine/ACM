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

stack<int> q,qm;

int x,s;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int mindiv[N],pri[N],cnt=0;
int vis[N];
void primes(int n){
    for(int i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=i,mindiv[i]=i;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||pri[j]*i>n) break;
            mindiv[pri[j]*i]=pri[j];
        }
    }
}

signed main(){

    // primes(100000);
    // cout<<cnt<<endl;

    // reverse(pri+1,pri+1+cnt);

    read(s),read(x);

    if(gcd(s,x)==1){
        cout<<1<<endl;
        cout<<s<<endl;
        return 0;
    }

    queue<int> q;
    while(gcd(abs(s),x)!=1){
        for(int i=1;;i++){
            if(abs(s-i)<=1e9&&gcd(abs(s-i),x)==1){q.push(s-i);break;}
            if(abs(s+i)<=1e9&&gcd(abs(s+i),x)==1){q.push(s+i);break;}
        }
        s=s-q.back();
    }

    if(q.size()+1>1000000){
        cout<<-1<<endl;
        return 0;
    }
    cout<<q.size()+1<<endl;
    cout<<s<<" ";
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}