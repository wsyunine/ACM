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
int mapp[N];

int main(){

    cin>>s;
    n=s.length();

    int idea=1;
    if(s.length()%2) idea=0;
    for(int i=1;i<=n;i+=2){
        if(s[i-1]!=s[i]) idea=0;
        if(s[i-1]==s[i]&&mapp[s[i-1]]){
            idea=0;
        }
        else if(s[i-1]==s[i]){
            mapp[s[i-1]]=1;
        }
    }

    if(idea) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}