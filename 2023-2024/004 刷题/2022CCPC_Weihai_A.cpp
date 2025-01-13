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

int n,m;
string s[110][6];
map<string,int> mapp;
int cnt[6],mn=1010101010,ans=0;

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) cin>>s[i][j];
    }

    read(m);
    string sop;int op;
    for(int i=1;i<=m;i++){
        cin>>sop;read(op);
        mapp[sop]=op;cnt[op]++;
    }

    for(int i=1;i<=5;i++) mn=min(mn,cnt[i]);

    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            if(mapp.find(s[j][i])!=mapp.end()) 
                if(mapp[s[j][i]]<=5) ans++,mapp[s[j][i]]=6;
        }
    }

    cout<<min(mn,ans)<<endl;

    return 0;
}