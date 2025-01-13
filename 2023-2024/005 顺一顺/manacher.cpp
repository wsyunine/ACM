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
#define N 22000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int len,n;
int p[N];
int res=0;
char str[N],s[N];

signed main(){

    scanf("%s",str+1);
    len=strlen(str+1);
    s[0]='~';n=0;
    for(int i=1;i<=len;i++) s[++n]='#',s[++n]=str[i];
    s[++n]='#';

    int mid=0,r=0;
    for(int i=1;i<=n;i++){
        if(i<r) p[i]=min(p[(mid<<1)-i],r-i+1);
        while(s[i+p[i]]==s[i-p[i]]) p[i]++;
        if(i+p[i]-1>r) r=i+p[i]-1,mid=i;
        if(p[i]-1>res) res=p[i]-1;
    }

    printf("%d\n",res);


    return 0;
}