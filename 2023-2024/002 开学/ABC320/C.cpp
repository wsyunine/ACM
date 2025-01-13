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

int s[N],ans=0x3f3f3f3f;
string a[4];
int n;
int num[8][4]={{},{1,2,3},{1,3,2},{2,3,1},{2,1,3},{3,2,1},{3,1,2}};

int main(){

    read(n);
    cin>>a[1]>>a[2]>>a[3];
    for(int i=0;i<=9;i++){
        for(int j=1;j<=6;j++){
            int op=0,k=0,tim=0;
            while(++k){
                if(tim>=3000) break;
                if(k==n+1) k=1;
                if(a[num[j][op]][k-1]==i+'0') op++;
                if(op==3){ans=min(ans,tim);break;}
                tim++;
            }
            // cout<<tim<<endl;
        }
    }

    if(ans==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}