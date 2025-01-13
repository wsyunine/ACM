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

int t;
int n;
int a[N],s=0;
int cnt[N];

int main(){

    read(t);
    while(t--){
        read(n);s=0;
        for(int i=1;i<=n;i++) read(a[i]),cnt[a[i]]=0;

        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
            if(cnt[a[i]]==2) s++;
        }

        if(s<2){cout<<-1<<endl;continue;}

        int idea=1;
        for(int i=1;i<=n;i++){
            if(cnt[a[i]]==1) cout<<1<<" ";
            else if(idea==1) idea=0,cnt[a[i]]=1,cout<<2<<" ";
            else cnt[a[i]]=1,cout<<3<<" ";
        }
        cout<<endl;
    }

    return 0;
}