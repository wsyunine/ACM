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

int n;
string s;

int main(){

    read(n);
    cin>>s;

    int idea=1;
    if(n%2==0) idea=0;
    for(int i=1;i<(n+1)/2;i++){
        if(s[i-1]!='1') idea=0;
    }
    if(s[(n+1)/2-1]!='/') idea=0;
    for(int i=(n+1)/2+1;i<=n;i++){
        if(s[i-1]!='2') idea=0;
    }

    if(idea) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}