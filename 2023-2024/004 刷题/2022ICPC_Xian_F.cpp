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

int n,c1,c2,ans=0;
char s[4];

int main(){

    read(n),read(c1),read(c2);

    for(int i=1;i<=n;i++){
        cin>>s;
        sort(s,s+3);
        if(s[0]==s[1]||s[1]==s[2]){
            ans+=min(c1*2,c2);
        }else ans+=min(c1*2,c2*2);
        ans+=min(c1,c2);
    }

    cout<<ans<<endl;

    return 0;
}