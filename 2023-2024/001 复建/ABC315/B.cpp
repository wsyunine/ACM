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
using namespace std;
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int m,d[110],sum=0;

int main(){

    cin>>m;
    for(int i=1;i<=m;i++) cin>>d[i],sum+=d[i];

    sum=(sum+1)/2;

    int t=1;
    while(sum>0){
        if(sum>d[t]) sum-=d[t];
        else{
            cout<<t<<" "<<sum<<endl;
            break;
        }
        t++;
    }

    return 0;
}
