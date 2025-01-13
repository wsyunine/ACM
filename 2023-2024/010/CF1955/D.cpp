#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<unordered_map>
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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,m,k;
int a[N];
unordered_map<int,pair<int,int>> mapp; 

int main(){

    read(t);
    while(t--){
        read(n),read(m),read(k);
        mapp.clear();
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1,op;i<=m;i++) read(op),mapp[op].first++;

        int cnt=0,res=0;
        for(int i=1;i<=m;i++){
            if(mapp[a[i]].first&&mapp[a[i]].second<mapp[a[i]].first) cnt++,mapp[a[i]].second++;
            else if(mapp[a[i]].first) mapp[a[i]].second++;
        }
        if(cnt>=k) res++;

        for(int i=m+1;i<=n;i++){
            if(mapp[a[i-m]].first&&mapp[a[i-m]].second<=mapp[a[i-m]].first) cnt--,mapp[a[i-m]].second--;
            else if(mapp[a[i-m]].first) mapp[a[i-m]].second--;
            if(mapp[a[i]].first&&mapp[a[i]].second<mapp[a[i]].first) cnt++,mapp[a[i]].second++;
            else if(mapp[a[i]].first) mapp[a[i]].second++;
            if(cnt>=k) res++;
            }

        cout<<res<<endl;
    }

    return 0;
}