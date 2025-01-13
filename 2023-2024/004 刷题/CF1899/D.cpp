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

int t;
int n,ans=0;
int a[N];
map<int,int> mapp;

signed main(){

    read(t);
    while(t--){
        read(n);
        mapp.clear();ans=0;
        for(int i=1;i<=n;i++) read(a[i]);

        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            int pos=a[i],j=0;
            ans+=mapp[a[i]];
            while(pos%2==0){
                pos/=2;j++;
                if(a[i]-pos==j) if(mapp.find(pos)!=mapp.end()) ans+=mapp[pos];
            }
            mapp[a[i]]++;
        }
        cout<<ans<<endl;
    }

    return 0;
}