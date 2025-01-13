#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1000010
#define int long long
const int Mod=998244353;

int n;
int k;
int t;
int f[3010],res=0;

void dfs(int s,int up,int sum,int ff){
    // cout<<sum<<endl;
    if(s==k-1){
        if(n-sum>=up) (res+=ff*f[n-sum]%Mod)%=Mod;
        return;
    }
    if(n-sum<up*(k-s)) return;
    if(sum==n) return;
    for(int i=up;i*(k-s)+sum<=n;i++){
        dfs(s+1,i,sum+i,ff*f[i]%Mod);
    }
}

signed main(){

    cin>>t;
    while(t--){
        cin>>n>>k;res=0;

        if(n<k){
            cout<<0<<endl;
            continue;
        }

        f[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=(i-1-1)/2+1;j++){
                (f[i]+=f[j]*f[i-j]%Mod)%=Mod;
            }
        }

        dfs(0,1,0,1);

        cout<<res<<endl;
    }

    return 0;
}