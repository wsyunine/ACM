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

int n,ans=0;
string s[N];
map<string,bool> mapp;

int main(){

    read(n);
    for(int i=1;i<=n;i++) cin>>s[i],mapp[s[i]]=1;

    for(int i=1;i<=n;i++){
        if(s[i].size()>447) continue;
        int len=s[i].size();
        string op;
        bool idea=1;
        for(int j=0;j<len;j++){
            op.clear();
            for(int k=j;k<len;k++){
                op.push_back(s[i][k]);
                if(mapp.find(op)==mapp.end()){idea=0;break;}
            }
            if(!idea){break;}
        }
        if(idea) ans=max(ans,len);
    }

    cout<<ans<<endl;

    return 0;
}