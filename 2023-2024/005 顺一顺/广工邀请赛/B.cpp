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

int n,m;
bool is[N];
int s[N],sum=0,p=0;

int main(){

    read(n),read(m);

    for(int i=1;i<=m;i++){
        int x;string si;
        read(x);cin>>si;
        if(is[x]) continue;
        if(si=="AC"){
            is[x]=1;sum++;
            p+=s[x];
        }else{
            s[x]++;
        }
    }

    cout<<sum<<" "<<p<<endl;

    return 0;
}