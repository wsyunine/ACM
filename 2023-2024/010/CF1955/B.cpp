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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,t,c,d;
unordered_map<int,int> mapp;

int main(){

    read(t);
    while(t--){
        mapp.clear();
        read(n),read(c),read(d);
        int minn=1e9+7;
        for(int i=1,k;i<=n*n;i++) read(k),mapp[k]++,minn=min(minn,k);

        bool idea=1;
        
        for(int i=1;i<=n;i++){
            int pos=minn;
            for(int j=1;j<=n;j++){
                if(!mapp[pos]){idea=0;break;}
                mapp[pos]--;
                pos+=c;
            }
            minn+=d;
        }

        if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}