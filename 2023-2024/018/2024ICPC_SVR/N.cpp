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

int t;
char s1,s2,s3;
int a,b,c;

int main(){

    read(t);
    while(t--){
        cin>>s1>>s2>>s3;
        a=s1%'0';
        c=s3%'0';

        if(a>c){
            cout<<a<<">"<<c<<endl;
        }else if(a==c){
            cout<<a<<"="<<c<<endl;
        }else cout<<a<<"<"<<c<<endl;
    }

    return 0;
}