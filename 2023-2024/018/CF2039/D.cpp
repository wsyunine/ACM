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
int m;
int a[N],b[N];

int main(){

    read(t);
    while(t--){
        read(n);
        read(m);
        for(int i=1;i<=m;i++) read(a[i]);
        sort(a+1,a+1+m);
        reverse(a+1,a+1+m);
        for(int i=1;i<=n;i++) b[i]=0;

        int idea=0;
        for(int i=1;i<=n;i++){
            for(int j=i*2;j<=n;j+=i){
                b[j]=max(b[j],b[i]+1);
                if(b[j]+1>m) idea=1;
            }
        }

        if(idea){
            cout<<-1<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            printf("%d ",a[b[i]+1]);
        }
        cout<<endl;
    }

    return 0;
}