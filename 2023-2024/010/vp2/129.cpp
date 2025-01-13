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
#define N 2000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,k;
string op;
int mapp[N];

int main(){

    read(n),read(k);cin>>op;

    for(int i=1;i<=n;i++) mapp[i]=op[i-1]-'0';

    int sum=0;
    bool idea0=0,idea1=0;
    for(int i=1;i<=n;i++){
        if(mapp[i]==1) idea1=1;
        else idea0=1;
        if(idea0&&idea1){
            sum++;
            idea0=0,idea1=0;
        }
    }

    if(sum>=k){cout<<0<<endl;return 0;}

    if(!idea1&&!idea0){
        cout<<(k-sum)*2<<endl;
    }else if(idea0||idea1){
        cout<<(k-sum-1)*2+1<<endl;
    }

    return 0;
}