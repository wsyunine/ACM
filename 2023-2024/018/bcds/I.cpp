#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1000010

int n;
int t;
int a[N];
int mapp[N];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int mx=0,ans=-1;
        for(int i=1;i<=2000;i++) mapp[i]=-1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mapp[a[i]]=i,mx=max(mx,a[i]);
        vector<pair<int,int>> s;
        for(int i=1;i<=mx;i++) if(mapp[i]!=-1) s.push_back({i,mapp[i]});

        int x=s.size();
        for(int i=0;i<x;i++){
            for(int j=0;j<=i;j++){
                if(gcd(s[i].first,s[j].first)==1){
                    ans=max(ans,s[i].second+s[j].second);
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}