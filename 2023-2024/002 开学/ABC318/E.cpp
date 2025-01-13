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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,cnt=0,ans=0;

signed main(){

    read(n);
    vector<int> s(n+1);
    vector<int> pre(n+1);
    vector<int> suf(n+1);

    for(int i=1;i<=n;i++) read(s[i]);

    for(int i=n;i>=3;i--) suf[s[i]]++;
    pre[s[1]]++;
    cnt=pre[s[1]]*suf[s[1]];
    for(int i=2;i<n;i++){
        // cout<<i<<" "<<cnt<<endl;
        // cout<<cnt<<" "<<i<<endl;
        ans+=cnt-pre[s[i]]*suf[s[i]];
        // cout<<s[i]<<" "<<ans<<endl;
        cnt-=pre[s[i]]*suf[s[i]];
        cnt-=pre[s[i+1]]*suf[s[i+1]];
        if(s[i]==s[i+1]) cnt+=pre[s[i]]*suf[s[i]];
        pre[s[i]]++;
        suf[s[i+1]]--;
        cnt+=pre[s[i]]*suf[s[i]];
        cnt+=pre[s[i+1]]*suf[s[i+1]];
        if(s[i]==s[i+1]) cnt-=pre[s[i]]*suf[s[i]];
    }

    cout<<ans<<endl;

    return 0;
}