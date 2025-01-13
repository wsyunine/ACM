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
int tmp=0;

signed main(){

    read(n);
    for(int i=1;i<=n;i++){
        char c;
        int p;
        cin>>c>>p;
        if(c=='P'){
            tmp+=p;
        }else{
            if(p-tmp>=1){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
            tmp-=min(p,tmp);
        }
    }

    return 0;
}