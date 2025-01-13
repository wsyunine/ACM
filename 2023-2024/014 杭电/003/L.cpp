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

int n,l,d;
int a[N];
int t;

int main(){

    read(t);
    while(t--){
        read(n),read(l),read(d);
        for(int i=1;i<=n;i++) read(a[i]);
        sort(a+2,a+1+n);
        int st=lower_bound(a+2,a+1+n,l)-a;
        st--;
        if(a[1]>=l){
            // cout<<st<<endl;
            if(st<4){cout<<"No"<<endl;continue;}
            if(a[1]-a[2]>d){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            if(st<3){cout<<"No"<<endl;continue;}
            if(a[n]-min(a[1],a[2])>d){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }

    return 0;
}