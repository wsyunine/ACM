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

int n,m;
string s[N];
short d[101][100010];

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++) cin>>s[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            d[i][j+1]=s[i][j]-'0';
        }
    }

    for(int i=1;i<=n;i++){

    }

    return 0;
}