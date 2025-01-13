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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N],k,s=0,ans=0x3f3f3f3f,mx=0;
priority_queue<int,vector<int>,less<int>> q;

int main(){

    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]),q.push(a[i]),mx=max(mx,a[i]);

    if(k==1){
        cout<<mx<<endl;
        return 0;
    }

    s=0;

    while(q.top()!=0){
        s++;
        int t=q.top();
        q.pop();
        t=t/k;
        q.push(t);
        ans=min(ans,s+q.top());
    }

    cout<<ans<<endl;

    return 0;
}