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
#include<unordered_map>
using namespace std;
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N],res[N];
unordered_map<int,int> mapp;

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=n;i++){
        if(!mapp[a[i]]){
            mapp[a[i]]=i;
            res[i]=-1;
        }else{
            res[i]=mapp[a[i]];
            mapp[a[i]]=i;
        }
    }

    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}