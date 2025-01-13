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

int main(){

    int P;
    cin>>P;
    while(P--){
        double a1,a2,b1,b2,c1,c2;
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;
        a1/=10;b1/=10;c1/=10;a2/=10;b2/=10;c2/=10;
        double s=a1*a2+b1*b2+c1*c2;
        if(s==1){
            cout<<"Sorry,NoBruteForce"<<endl;
            continue;
        }
        double p1=1-s,ans=0;
        for(int i=1;i<=1000;i++){
            ans+=(p1*i);
            p1=p1*s;
        }
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }

    return 0;
}