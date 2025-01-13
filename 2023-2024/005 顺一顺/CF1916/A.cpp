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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t,n,k,b[N],s=1;

signed main(){

    read(t);
    while(t--){
        s=1;
        read(n),read(k);
        for(int i=1;i<=n;i++){
            read(b[i]),s*=b[i];
            
        }
        if(s>2023){
            cout<<"NO"<<endl;
            continue;
        }

        if(2023%s!=0) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<2023/s<<" ";
            for(int i=2;i<=k;i++) cout<<"1 ";
            cout<<endl;
        }
    }

    return 0;
}