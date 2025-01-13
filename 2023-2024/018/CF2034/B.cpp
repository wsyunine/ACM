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

int t;
int n,m,k;
string str;

int main(){

    read(t);
    while(t--){
        int res=0;
        read(n);read(m),read(k);
        cin>>str;
        str=' '+str;

        int s0=0,l=1;
        for(int i=1;i<=m;i++) s0+=(str[i]=='0');
        if(s0==m){
            s0=m-1;res++;
            for(int i=m;i<=min(m+k-1,n);i++) str[i]='1';
        }
        for(int i=m+1,j=1;i<=n;i++,j++){
            s0-=(str[j]=='0');
            s0+=(str[i]=='0');
            if(s0==m){
                s0=m-1;res++;
                for(int p=i;p<=min(i+k-1,n);p++){
                    str[p]='1';
                }
            }
        }

        cout<<res<<endl;

    }

    return 0;
}