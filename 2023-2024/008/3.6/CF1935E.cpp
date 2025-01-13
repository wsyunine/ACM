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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t,n;
int q;
pair<int,int> p[N];
int sum[N][30];

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(p[i].first),read(p[i].second);

        

        read(q);
        for(int i=1;i<=q;i++){

        }
    }

    return 0;
}