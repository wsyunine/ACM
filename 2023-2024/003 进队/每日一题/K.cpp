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
#define N 300010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

bool pre[N],sup[N];
string s1,s2;
int n,m;

int main(){

    cin>>s1>>s2;
    n=s1.size(),m=s2.size();

    pre[0]=1;
    for(int i=1;i<=n;i++){
        if((s1[i-1]==s2[i-1])||(s1[i-1]=='?')||(s2[i-1]=='?')) pre[i]=1;
        else{pre[i]=0;break;}
    }

    sup[n+1]=1;
    for(int i=n,j=m;j>0;i--,j--){
        if((s1[i-1]==s2[j-1])||(s1[i-1]=='?')||(s2[j-1]=='?')) sup[i]=1;
        else{sup[i]=0;break;}
    }

    for(int i=0;i<=m;i++){
        if(pre[i]&sup[n-m+i+1]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}