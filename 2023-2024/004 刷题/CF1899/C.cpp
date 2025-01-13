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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
ll a[N],s[N];
priority_queue<int,vector<int>,greater<int>> q;

int main(){

    read(t);
    while(t--){
        read(n);
        s[0]=0;
        while(!q.empty()) q.pop();
        ll ans=-0x3f3f3f3f;
        for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];

        ans=a[1];
        q.push(0);
        for(int i=2;i<=n;i++){
            if(abs(a[i]%2)==abs(a[i-1]%2)){
                while(!q.empty()) q.pop();
                q.push(s[i-1]);
            }else{
                q.push(s[i-1]);
            }
            ans=max(ans,s[i]-q.top());
        }
        cout<<ans<<endl;
    }

    return 0;
}