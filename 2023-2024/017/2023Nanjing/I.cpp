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

int n;
int t;
int m;
pair<int,int> a[N];

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        for(int i=1;i<=m;i++) read(a[i].first),read(a[i].second);

        sort(a+1,a+1+m);

        int tmp=0,tmpn=0,id=1;
        for(int i=1;i<=m;i++){
            if(a[i].first-tmp>=a[i].second+1||a[i].first-tmp==a[i].second-tmpn) tmp=a[i].first,tmpn=a[i].second;
            else id=0;
        }        

        if(id) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}