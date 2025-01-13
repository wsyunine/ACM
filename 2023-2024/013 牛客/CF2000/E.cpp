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
int n,m,k;
int w;
int a[N];
priority_queue<int> s1,s2;

signed main(){

    read(t);
    while(t--){
        while(s1.size()) s1.pop();
        read(n),read(m),read(k);
        vector<vector<int>> mapp(n+2,vector<int>(m+2,0));
        read(w);
        for(int i=1;i<=w;i++) read(a[i]),s2.push(a[i]);

        for(int i=1,j=m;i<=j;i++,j--){
            mapp[1][i]=mapp[1][j]=min(min(i,k),m-k+1);
        }
        for(int i=1,j=n;i<=j;i++,j--){
            mapp[i][1]=mapp[j][1]=min(min(i,k),n-k+1);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mapp[i][j]){s1.push(mapp[i][j]);continue;}
                mapp[i][j]=mapp[1][j]*mapp[i][1];
                s1.push(mapp[i][j]);
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<mapp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        long long ans=0;
        while(s2.size()){
            ans+=s1.top()*s2.top();
            s1.pop();
            s2.pop();
        }
        cout<<ans<<endl;
    }

    return 0;
}