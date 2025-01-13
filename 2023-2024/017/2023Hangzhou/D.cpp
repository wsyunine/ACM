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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

ll a,b,c,d,t;
ll e,f;

int main(){

    read(t);
    while(t--){
        read(a),read(b),read(c),read(d);

        e=a+c,f=b+d;

        ll res=-1;

        if(f-e>10){
            cout<<9<<endl;
        }else{

            for(int i=e;i<=f;i++){
                ll pos=i;
                while(pos){
                    res=max(res,pos%10);
                    pos/=10;
                }
            }

            cout<<res<<endl;
        }
    }

    return 0;
}