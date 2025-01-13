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
#define N 600010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t[N];
int n,m;

void add(int x,int y){
    for(;x<=n;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++){
        int a;
        read(a);
        add(i,a);
    }
    // for(int i=1;i<=n;i++) cout<<t[i]<<" ";

    for(int i=1;i<=m;i++){
        int idx,a,b;
        read(idx);
        if(idx==1){
            read(a);read(b);
            add(a,b);
            // for(int j=1;j<=n;j++) cout<<t[j]<<" ";
        }else{
            read(a),read(b);
            cout<<query(b)-query(a-1)<<endl;
        }   
    }

    return 0;
}