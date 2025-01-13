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
int mapp[1010][1010],s[N],ss[1010][1010],sum=0;

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++){
        read(s[i]);
        for(int j=1;j<=s[i];j++){
            int op;
            read(op);
            if(!ss[i][op]) ss[i][op]=1;
        }
    }

    bool ans=0,dd=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) if(ss[j][i]){sum++;break;}

        for(int j=1,k=0;j<=n;j++){
            if(ss[j][i]) k++;
            if(k>1){ans^=1;}
            if(k>2){dd=1;break;}
        }
    }
    if(sum==1) cout<<"Alice"<<endl;
    else if(dd) cout<<"Alice"<<endl;
    else if((sum&1)^ans) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;

    return 0;
}