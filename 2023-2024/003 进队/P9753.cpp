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
#define N 2000010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

ll n,ans=0;
string s;
int nxt[N][30],cnt[N];

int main(){

    read(n);
    cin>>s;
    
    for(int i=0;i<n;i++) s[i]-='a',s[i]+=1;
    for(int i=n-2;i>=0;i--){
        if(s[i]==s[i+1]){
            for(int j=1;j<=26;j++) nxt[i][j]=nxt[i+2][j];
            if(i+2<n) nxt[i][s[i+2]]=i+2;
            cnt[i]=cnt[i+2]+1;  
        }else if(nxt[i+1][s[i]]){
            int r=nxt[i+1][s[i]];
            for(int j=1;j<=26;j++) nxt[i][j]=nxt[r+1][j];
            if(r+1<n) nxt[i][s[r+1]]=r+1;
            cnt[i]=cnt[r+1]+1;
        }
    } 

    for(int i=0;i<n;i++) ans+=cnt[i];

    cout<<ans<<endl;
    
    return 0;
}