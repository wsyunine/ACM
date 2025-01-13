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
int a[N][7],ans=0;

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) read(a[i][j]);
    }

    int t[6];
    for(t[1]=0;t[1]<=9;t[1]++){
        for(t[2]=0;t[2]<=9;t[2]++){
            for(t[3]=0;t[3]<=9;t[3]++){
                for(t[4]=0;t[4]<=9;t[4]++){
                    for(t[5]=0;t[5]<=9;t[5]++){
                        bool idea=0;
                        for(int i=1;i<=n;i++){
                            int cnt=-1,d=1e9+7;
                            bool tmp=1;
                            for(int j=1;j<=5;j++) if(a[i][j]!=t[j]) tmp=0;
                            if(tmp){idea=1;break;}
                            for(int j=1;j<=5;j++){
                                if(a[i][j]==t[j]) continue;
                                else if(cnt==-1) d=a[i][j]-t[j],cnt=j;
                                else if(cnt==j-1&&((t[j]+d)%10+10)%10==a[i][j]) continue;
                                else{idea=1;break;} 
                            }
                            if(idea) break;
                        }
                        if(idea) continue;
                        ans++;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}