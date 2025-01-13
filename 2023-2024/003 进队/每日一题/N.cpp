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

int f[N];
int n,m;
int cnt=0;

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

int merge(int x,int y){
    int a=find(x),b=find(y);
    if(a==b) return false;
    f[a]=b;
    return true;
}

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++) f[i]=i;

    for(int i=1;i<=m;i++){
        int a,b;
        read(a),read(b);
        cnt+=merge(a,b);
    }

    cout<<m-cnt<<endl;
    
    return 0;
}