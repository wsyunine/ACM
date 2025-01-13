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
using namespace std;
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
pair<int,int> p[300010];
bool is=0;
int fi,se,ans=0;

const bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return (a.second==b.second)?(a.first<b.first):(a.second>b.second);
}

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
    }

    sort(p+1,p+1+n,cmp);

    for(int i=1;i<=n;i++){
        if(i==1) fi=p[i].first,se=p[i].second;
        if(!is&&i!=1&&p[i].first==fi){
            is=1;
            ans=max(ans,se+p[i].second/2);
        }
        if(p[i].first!=fi) ans=max(ans,se+p[i].second);
    }

    cout<<ans<<endl;

    return 0;
}
