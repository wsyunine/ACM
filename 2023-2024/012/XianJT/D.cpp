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
int m;
pair<int,int> s[N],cnt[N];

bool cmp(pair<int,int> a,pair<int,int> b){
    return cnt
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) cnt[i].second=i;
    for(int i=1;i<=n;i++){
        read(s[i].first),read(s[i].second);
        cnt[s[i].first].first++;
    }
    sort(cnt+1,cnt+1+n);
    sort(s+1,s+1+n);

    return 0;
}