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
int a[N],s[N],m=0;
int pos1,pos2,s1[2],s2[2];
int res1[N],res2[N];
vector<int> num[110];

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]),num[a[i]].push_back(a[i]),s[a[i]]++,m+=(s[a[i]]==1);
    
    for(int i=1;i<=m;i++){
        sort(num[i].begin(),num[i].end());
    }

    int st=1;
    while(s[a[st]]==1){
        res1[st]=res2[st]=res1[st-1]^1;
        s1[res1[st]]++;
        s2[res2[st]]++;
        st++;
    }
    res1[st]=0;
    res2[st]=1;
    pos1=st,pos2=st;
    int pos=st+1;
    for(int i=pos;i<=n;i++){
        int t=a[i];
    }

    return 0;
}