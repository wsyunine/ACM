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

int mn=1000000,sm;
void dfs(int ss,int xx,int sum){
    // cout<<mn<<endl;
    if(sum==s){
        if(q.size()<mn) mn=q.size(),sm=sum,qm=q;
        return;
    }
    if(q.size()>=mn) return;
    if(q.size()+abs(s-sum)<mn){
        qm=q;sm=sum;
        mn=q.size()+abs(s-sum);
    }
    // if(pri[ss]>s) return;
    if(ss>cnt) return;
    if(xx-mn>s){dfs(ss+1,pri[ss+1],sum);return;}
    if(sum+xx*pri[ss]<=s){dfs(ss,xx*pri[ss],sum);return;}
    if(vis[ss]){dfs(ss+1,pri[ss+1],sum);return;}

    for(int j=0;sum+j*xx<=s;j++){
        dfs(ss,xx*pri[ss],sum+j*xx);
        q.push(xx);
    }
    while(q.size()&&q.top()==xx) q.pop();
}

void dfs(int ss,int sum){
    // cout<<pri[ss]<<" "<<sum<<" "<<mn<<endl;
    if(1+abs(s-sum)<mn){
        sm=sum;
        mn=1+abs(s-sum);
    }
    // if(1+abs(s-sum*pri[ss])>mn) return;
    if(ss>cnt) return;
    if(vis[ss]){dfs(ss+1,sum);return;}

    for(int j=1;(sum*j<=s)||(1+abs(sum*j-s)<mn);j*=pri[ss]){
        dfs(ss+1,sum*j);
    }
}

signed main(){

    primes(100000);
    // cout<<cnt<<endl;

    reverse(pri+1,pri+1+cnt);

    read(s),read(x);

    if(gcd(s,x)==1){
        cout<<1<<endl;
        cout<<s<<endl;
        return 0;
    }

    // int buzz;
    // for(int i=1;;i++){
    //     if(gcd(s-i,x)==1){buzz=s-i;break;}
    //     if(gcd(s+i,x)==1){buzz=s+i;break;}
    // }

    // int id=0;
    // if(buzz>s) id=1;

    // s=abs(buzz-s);

    for(int i=1;i<=cnt;i++){
        if(gcd(pri[i],x)!=1) vis[i]=1;
    }

    dfs(1,pri[1],0);

    // cout<<2+abs(sm-s)<<endl;
    // cout<<buzz<<" "<<(id?-sm:sm)<<" ";
    // if(sm<=s){
    //     for(int i=sm+1;i<=s;i++) cout<<(id?-1:1)<<" ";
    //     cout<<endl;
    // }else{
    //     for(int i=s+1;i<=sm;i++) cout<<(id?1:-1)<<" ";
    //     cout<<endl;
    // }

    if(qm.size()==0){
        cout<<-1<<endl;
        return 0;
    }

    

    cout<<qm.size()+abs(s-sm)<<endl;
    while(qm.size()){
        cout<<qm.top()<<" ";
        qm.pop();
    }
    if(sm<=s){
        for(int i=sm+1;i<=s;i++) cout<<1<<" ";
        cout<<endl;
    }else{
        for(int i=s+1;i<=sm;i++) cout<<-1<<" ";
        cout<<endl;
    }
    
    return 0;
}