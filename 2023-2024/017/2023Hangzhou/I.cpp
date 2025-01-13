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

int n;
int t;
int a[N],p[N];

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]),p[a[i]]=i;

        if(a[1]>a[n]){
            printf("1\n1 %d\n",n);
            continue;
        }

        vector<pair<int,int>> res;
        while(1){
            int l=n+1,aa,bb,ll=0;
            for(int i=n;i>=1;i--){
                if(p[i]-l>ll) ll=p[i]-l,aa=l,bb=p[i];
                l=min(l,p[i]);
            }
            if(ll==0) break;
            sort(a+aa,a+bb+1);
            for(int i=1;i<=n;i++) p[a[i]]=i;
            res.push_back({aa,bb});
        }
        
        printf("%d\n",(int)res.size());
        for(auto i:res){
            printf("%d %d\n",i.first,i.second);
        }
    }

    return 0;
}