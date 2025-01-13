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

string s,t,ans;
int f[3010][3010];

int main(){

    cin>>s>>t;
    int lens=s.size(),lent=t.size();
    for(int i=1;i<=lens;i++){
        for(int j=1;j<=lent;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(s[i-1]==t[j-1]) f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
            // cout<<f[i][j]<<" ";
        }
        // cout<<endl;
    }

    int i=lens,j=lent;
    while(i>0&&j>0){
        if(s[i-1]==t[j-1]) ans.push_back(s[i-1]),i--,j--;
        else if(f[i-1][j]>=f[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;

    return 0;
}