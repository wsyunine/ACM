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

int n,m,k,res=0x3f3f3f3f;

int main(){

    read(n),read(m),read(k);
    vector<string> s(n+1);

    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    
    for(int i=1;i<=n;i++){
        int sx=0,so=0;
        for(int j=0;j<m;j++){
            if(s[i][j]=='o'){
                so++;
            }else if(s[i][j]=='.'){
                sx++;
            }else{
                if(so+sx>=k) res=min(res,max(k-so,0));
                so=0,sx=0;
            }
        }
        if(so+sx>=k) res=min(res,max(k-so,0));
        so=0,sx=0;
    }

    for(int i=0;i<m;i++){
        int sx=0,so=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='o'){
                so++;
            }else if(s[j][i]=='.'){
                sx++;
            }else{
                if(so+sx>=k) res=min(res,max(k-so,0));
                so=0,sx=0;
            }
        }
        if(so+sx>=k) res=min(res,max(k-so,0));
        so=0,sx=0;
    }

    if(res==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<res<<endl;

    return 0;
}