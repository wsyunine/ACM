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
#define N 200010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,x;
int s[N];
int q[N];
int fr=0,bk=0;

int check(int x){
    s[0]=x;
    s[n+1]=x;

    int cnt=0;

    fr=0,bk=-1;
    
    for(int i=0;i<=n+1;i++){
        if(fr>bk){
            q[++bk]=min(s[i],x);
            continue;
        }
        while(fr<=bk&&q[bk]<=s[i]) bk--;
        if(fr<=bk) cnt+=q[fr]-s[i];
        q[++bk]=min(s[i],x);
    }
    // cout<<x<<" "<<cnt<<endl;
    return cnt;
}

signed main(){

    read(t);
    while(t--){

        int l=1,r=1e9,maxx=0;

        read(n);
        read(x);
        for(int i=1;i<=n;i++) read(s[i]),maxx=max(maxx,s[i]);

        r+=maxx;

        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)<=x) l=mid;
            else r=mid-1;
        }

        cout<<l<<endl;

    }

    return 0;
}