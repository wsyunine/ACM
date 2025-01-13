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

int n;
int b,c,d;

signed main(){

    int t;
    read(t);
    while(t--){
        read(b),read(c),read(d);

        int op=1,id=1,res=0;
        while(b||c||d){
            int bb=b%2,cc=c%2,dd=d%2;
            if(bb==1&&cc==0){
                if(dd==0) id=0;
            }
            if(bb==0&&cc==0){
                res+=dd*op;
            }
            if(bb==1&&cc==1){
                res+=(bb-dd)*op;
            }
            if(bb==0&&cc==1){
                if(dd==1) id=0;
            }
            op*=2;
            b/=2;
            c/=2;
            d/=2;
        }
        if(!id) cout<<-1<<endl;
        else cout<<res<<endl;
    }

    return 0;
}