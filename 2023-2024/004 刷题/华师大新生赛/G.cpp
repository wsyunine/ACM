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
string s;
int idea=-1;

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        idea=-1;
        cin>>s;
        if(s=="red") idea=-1;
        else if(s=="yellow") idea=1;
        else idea=0;

        cin>>s;
        if(idea!=-1);
        else if(s=="no") idea=0;

        cin>>s;
        if(idea!=-1);
        else if(s=="mane") idea=0;
        else if(s=="nothing") idea=0;

        cin>>s;
        if(idea!=-1);
        else if(s=="yes") idea=1;
        else idea=0;

        if(idea==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}