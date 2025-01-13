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

int n;
int W,k;
pair<int,ll> gd[5010]; 
priority_queue<ll,vector<ll>,greater<ll>> q;
ll f[5010][10010];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first==b.first?a.second>b.second:a.first>b.first;
}

signed main(){

    read(n),read(W),read(k);
    for(int i=1;i<=n;i++){
        read(gd[i].first),read(gd[i].second);
    }

    sort(gd+1,gd+1+n,cmp);

    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<gd[i].first<<" "<<gd[i].second<<endl;
    // }

    for(int i=n;i>=1;i--){
        for(int j=W;j>=gd[i].first;j--){
            f[i][j]=max(f[i+1][j],f[i+1][j-gd[i].first]+gd[i].second);
        }
        for(int j=gd[i].first-1;j>=0;j--){
            f[i][j]=f[i+1][j];
        }
        //cout<<f[i][W]<<endl;
    }

    ll tmp=0,res=0;
    for(int i=1;i<=k;i++) q.push(gd[i].second),tmp+=gd[i].second;

    for(int i=k+1;i<=n;i++){
        res=max(res,tmp+f[i][W]);
        //cout<<res<<endl;
        if(q.size()&&gd[i].second>q.top()){
            tmp-=q.top();
            tmp+=gd[i].second;
            q.pop();
            q.push(gd[i].second);
        }
    } 
    res=max(res,tmp);

    cout<<res<<endl;

    return 0;
}
/*

4 10 1
9 10
10 1
3 5
5 20

*/