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

int k,n;
string s;

int main(){

    read(n),read(k);
    cin>>s;

    int tmp=0,res=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='O') tmp++;
        else{
            tmp=0;
        }
        if(tmp==k){
            tmp=0;
            res++;
        }
    }

    cout<<res<<endl;

    return 0;
}