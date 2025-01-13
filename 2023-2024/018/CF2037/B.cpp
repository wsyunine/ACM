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
int s[N],n,m,k,a[N];

int main(){

    read(t);
    while(t--){
        read(k);n=-1,m=-1;
        for(int i=1;i<=k;i++) s[i]=0;
        for(int i=1;i<=k;i++) read(a[i]),s[a[i]]++;

        k-=2;

        for(int i=1;i<=k+2;i++){
            if(k%a[i]==0&&k/a[i]==a[i]&&s[a[i]]>=2){
                n=a[i];
                m=a[i];
                break;
            }
            if(k%a[i]==0&&k/a[i]!=a[i]&&s[a[i]]&&s[k/a[i]]){
                n=a[i];
                m=k/a[i];
                break;
            }
        }

        cout<<n<<" "<<m<<endl;
    }

    return 0;
}