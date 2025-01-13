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

int m,n;
int mapp[1010][1010],l=0,k=0;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++){
        int ll=0;
        for(int j=1;j<=m;j++){
            char op;
            cin>>op;
            if(op=='.') mapp[i][j]=0;
            else mapp[i][j]=1,ll++;
        }
        l=max(ll,l);
    }

    for(int i=1;i<=m;i++){
        int kk=0;
        for(int j=1;j<=n;j++){
            if(mapp[j][i]) kk++;
        }
        k=max(kk,k);
    }

    if(l==0||k==0){
        return 0;
    }

    int g=gcd(l,k);
    l=l/g;
    k=k/g;

    for(int i=1;i<=k;i++){
        for(int j=1;j<=l;j++){
            cout<<'x';
        }
        cout<<endl;
    }

    return 0;
}