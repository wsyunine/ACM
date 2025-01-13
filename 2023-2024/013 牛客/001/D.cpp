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
#define N 2100010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
ll s=0,a[N];
int t[22][N];

void add(int a,int b,int id){
    // cout<<a<<endl;
    a++;
    for(;a<=(1<<21);a+=a&-a) t[id][a]+=b;
}

int query(int a,int id){
    a++;
    if(a<=0) return 0;
    int res=0;
    for(;a;a-=a&-a) res+=t[id][a];
    return res;
}

void del(){
    s--;
    for(int i=0;i<=20;i++){
        int op=1<<(i+1);
        add(((-a[s])%op+op)%op,-1,i);
    }
}

int add_(int x){
    s++;
    a[s]=a[s-1]+x;
    for(int i=0;i<=20;i++){
        int op=1<<(i+1);
        add(((-a[s-1])%op+op)%op,1,i);
    }
    int ans=0;
    for(int i=0,j=1;i<=20;i++,j<<=1){
        ll op=a[s]%(j<<1),res=0;
        if(op<=j){
            res=query((j<<1)-op-1,i)-query(j-op-1,i);
            // cout<<j-op<<" "<<(j<<1)-op<<endl;
        }else{
            res=query((j<<1)-op-1,i)+query((j<<2)-op-1,i)-query((j<<1)+j-op-1,i);
        }
        ans+=(res%2)*j;
    }
    return ans;
}

int main(){

    read(n);
    // for(int i=0;i<=20;i++) add(0,1,i);
    for(int i=1;i<=n;i++){
        int idx,x;
        read(idx),read(x);
        for(int j=1;j<=idx;j++) del();
        cout<<add_(x)<<endl;
    }

    return 0;
}