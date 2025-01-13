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

int t;
int n,m;
int a[N];
int b[N];

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        int maxans=0,minans=0,cnt=0;
        for(int i=1;i<=n;i++) read(a[i]),cnt^=a[i];
        for(int i=1;i<=m;i++) read(b[i]);

        maxans=minans=cnt;

        if(n%2==0){
            for(int i=1;i<=m;i++){
                maxans=max(maxans,maxans&(!b[i]));
                minans=min(minans,minans&(!b[i]));
            }
        }else{
            for(int i=1;i<=m;i++){
                maxans=max(maxans,maxans|b[i]);
                minans=min(minans,minans|b[i]);
            }
        }
        
        cout<<minans<<" "<<maxans<<endl;

    }

    return 0;
}