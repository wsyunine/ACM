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
int n,a[N];

int main(){

    read(t);
    while(t--){
        read(n);
        int idea=0,sum=0;
        for(int i=1;i<=n;i++) read(a[i]);
        sort(a+1,a+1+n);
        int minn=a[1];
        for(int i=1;i<=n;i++){
            if(a[i]==minn) sum++;
            else if(a[i]%minn<minn&&a[i]%minn!=0) idea=1;
        }
        if(sum==1) cout<<"Yes"<<endl;
        else if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}