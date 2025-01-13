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
#define int long long
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t,a,b,c,d;

int gcd(int x,int y){
    return (y==0)?x:gcd(y,x%y);
}

signed main(){

    read(t);
    while(t--){
        read(a),read(b);
        if(a>b) swap(a,b);
        if(a==1){
            cout<<b*b<<endl;
            continue;
        }
        int g=gcd(a,b);
        
        c=a/g;d=b/g;
        if(g==a||g==b){
            int s=g*c*d;
            int m=-1;
            for(int i=2;i*i<=g;i++){
                if(s%i==0){m=i;break;}
            }
            if(m==-1) m=g;
            cout<<g*c*d*m<<endl;
        }else{
            cout<<g*c*d<<endl;
        }
    }

    return 0;
}