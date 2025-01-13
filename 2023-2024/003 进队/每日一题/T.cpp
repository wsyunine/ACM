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

int n;
int a[N],ans=0;
priority_queue<pair<int,int>> s;
int cnt=0,p[N];

signed main(){

    read(n);

    for(int i=1;i<=n;i++) read(a[i]);

    // for(int l=1;l<=n;l++){
    //     for(int i=1;i+l-1<=n;i++){
    //         if(a[i]!=a[i+l]) ans+=min(i,n-i-l+1);
    //         // cout<<i<<" "<<i+l<<" "<<ans<<endl;
    //     }
    // }

    for(int i=1;i<=n;i++) s.push(make_pair(min(i,n-i+1),a[i]));

    while(s.size()){
        auto t=s.top();
        s.pop();
        // cout<<t.first<<" "<<t.second<<endl;
        ans+=(cnt-p[t.second])*t.first;
        p[t.second]++;
        cnt++;
    }

    cout<<ans<<endl;

    return 0;
}