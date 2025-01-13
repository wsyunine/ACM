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

int n;


int main(){

    cin>>n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=n-i-j;k++){
                cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }

    return 0;
}