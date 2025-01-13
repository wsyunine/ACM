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

int t;
int n;
int dp[N][10];
string str;

int main(){

    read(t);
    while(t--){
        cin>>str;
        str=' '+str;
        for(int k=0;k<=str.length();k++) for(int i=0;i<=8;i++) dp[k][i]=0;
        dp[0][0]=1;
        for(int i=1;i<=str.length();i++){
            int tmp=str[i]%'0';
            for(int j=0;j<=8;j++){
                if(str[i]=='2'){
                    dp[i][(j+2)%9]|=dp[i-1][j];
                    dp[i][(j+4)%9]|=dp[i-1][j];
                }else if(str[i]=='3'){
                    dp[i][(j+3)%9]|=dp[i-1][j];
                    dp[i][(j+9)%9]|=dp[i-1][j];
                }else{
                    dp[i][(j+tmp)%9]|=dp[i-1][j];
                }
            }
        }
        if(dp[str.length()][0]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}