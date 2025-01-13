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
int n;
int x,m;

signed main(){

    read(t);
    while(t--){
        read(x),read(m);
        int res=(m>=x);
        
        for(int i=1;i<=(1ll<<((long long)log2(x)+1))-1;i++){
            if((i^x)&&(i^x)<=m&&i%(i^x)==0) res++;
        }

        if(m<=(1ll<<((long long)log2(x)+1))-1){
            cout<<res<<endl;
            continue;
        }

        int y=(long long)log2(x)+1;

        int tmp=0;
        for(int i=60;i>=y;i--){
            if((m>>i)&1){
                if(!tmp){
                    res+=((1ll<<i)-1)/x-1ll;
                }else{
                    res+=((((1ll<<i)-1)|tmp)/x)-((tmp-1)/x);
                }
                tmp=tmp|(1ll<<i);
            }
        }

        for(int i=tmp;i<=tmp+((1ll<<y)-1);i++){
            if(i%x==0&&(i^x)<=m) res++;
        }

        cout<<res<<endl;

    }

    return 0;
}