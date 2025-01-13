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
int n;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);

        for(int i=1;i<=n;i++) read(a[i]);

        int idea=0,i=1,j=0;
        for(i=1,j=n;i<=j;i++){
            while(a[j]>=a[i]&&i<j){
                if(a[j]<a[j-1]){idea=1;break;}
                j--;
            }
            if(idea) break;
        }
        if(idea) cout<<-1<<endl;
        else cout<<i-2<<endl;
    }

    return 0;
}