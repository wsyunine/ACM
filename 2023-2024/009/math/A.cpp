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

int pri[1000010],mindiv[1000010],cnt=0,ispri[1000010];

void prime(int x){
    for(int i=2;i<=x;i++){
        if(!mindiv[i]) mindiv[i]=i,pri[++cnt]=i,ispri[i]=1;
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>x||pri[j]>mindiv[i]) break;
            mindiv[i*pri[j]]=pri[j];
        }
    }
}

int main(){

    prime(1000000);
    
    while(1){
        cin>>n;
        if(!n){break;}
        int ans=0;
        for(int i=1;i<=cnt;i++){
            if(n-pri[i]<pri[i]) break;
            if(ispri[n-pri[i]]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}