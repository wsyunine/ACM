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

int t;
int n;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);

        int id=1;
        for(int i=2;i<=n;i++){
            if((abs(a[i]-a[i-1])!=5)&&(abs(a[i]-a[i-1])!=7)) id=0;
        }
        if(id) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}