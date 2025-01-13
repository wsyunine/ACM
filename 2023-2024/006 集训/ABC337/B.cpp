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

string s;
int n;

int main(){

    cin>>s;
    n=s.length();
    int idea=1;
    int op1=0,op2=0;
    for(int i=0;i<n;i++){
        if(!op1&&s[i]=='B') op1=1;
        if(!op2&&s[i]=='C') op2=1;
        if(op1==0&&op2==0&&s[i]!='A'){
            idea=0;break;
        }else if(op1==1&&op2==0&&s[i]!='B'){
            idea=0;break;
        }else if(op1==1&&op2==1&&s[i]!='C'){
            idea=0;break;
        }
    }
    if(idea) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}