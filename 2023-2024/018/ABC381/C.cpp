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
string s;
int pre1[N],suf2[N];

int main(){

    read(n);
    cin>>s;
    
    if(s[0]=='1') pre1[0]=1;
    for(int i=1;i<n;i++){
        if(s[i]=='1') pre1[i]=pre1[i-1]+1;
        else pre1[i]=0;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='2') suf2[i]=suf2[i+1]+1;
        else suf2[i]=0;
    }

    int ans=0;
    if(s[0]=='/') ans=max(ans,1);
    for(int i=1;i<n;i++){
        if(s[i]=='/') ans=max(ans,min(suf2[i+1],pre1[i-1])*2+1);
    }

    cout<<ans<<endl;

    return 0;
}