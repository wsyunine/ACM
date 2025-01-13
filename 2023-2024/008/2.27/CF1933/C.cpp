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

int t,a,b,l;
int mapp[1000010];

int main(){

    read(t);
    while(t--){
        memset(mapp,0,sizeof mapp);
        read(a),read(b),read(l);
        int pos=l,ans=0,opt=0;
        opt=pos;
        if(!mapp[opt]) ans++,mapp[opt]=1;
        while(opt%b==0){opt/=b,mapp[opt]==0?ans++,mapp[opt]=1:0;}
        while(pos%a==0){
            pos/=a;
            opt=pos;
            if(!mapp[opt]) ans++,mapp[opt]=1;
            while(opt%b==0){opt/=b,mapp[opt]==0?ans++,mapp[opt]=1:0;}
        }
        cout<<ans<<endl;
    }

    return 0;
}