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
int n,m;
string s[N];

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        int tmp=0,res=-1;
        for(int i=1;i<=n;i++){
            cin>>s[i],tmp+=s[i].length();
            // cout<<tmp<<endl;
            if(tmp>m){
                res=i-1;
                tmp=-0x3f3f3f3f;
            }
        }
        if(res==-1) res=n;

        cout<<res<<endl;
    }

    return 0;
}