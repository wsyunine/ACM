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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

ll n;
int pri[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll ans1,ans2;

void dfs(ll sum,ll pos,int k,int t){
    if(ans1<sum){
        ans1=sum;
        ans2=pos;
    }else if(sum==ans1&&pos<ans2){
        ans2=pos;
    }
    if(k>14) return;
    ll op=pos;
    for(int i=1;i<=t;i++){
        if(op*pri[k]>n) break;
        op*=pri[k];
        dfs(sum*(i+1),op,k+1,i);
    }
}

int main(){ 

    while(cin>>n){
        dfs(1,1,0,100);
        cout<<ans2<<endl;
    }

    return 0;
}