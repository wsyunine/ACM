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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,k;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);read(k);
        for(int i=1;i<=n;i++) read(a[i]);
        sort(a+1,a+1+n);
        int cnte=0,cnto=0,_k=0;

        int i,op;
        for(i=0,op=1;cnte<k||cnto<k;i++){
            if(a[op]==i&&op<=n){op++;continue;}
            // cout<<i<<" ";
            if(i%2) cnto++;
            else cnte++;
        }
        if(cnte==cnto){
            while(a[op]==i&&op<=n) op++,i++;
            _k=i;
        }
        
        if(cnte<cnto) cout<<"Bob"<<endl;
        else if(cnto<cnte) cout<<"Alice"<<endl;
        else{
            if(_k%2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
    
    return 0;
}