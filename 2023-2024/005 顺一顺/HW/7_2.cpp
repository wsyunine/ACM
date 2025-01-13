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

void stringReverse(string s,int po){
    int len=s.size();
    if(po==len){
        cout<<s[po-1];
        return;
    }
    stringReverse(s,po+1);
    cout<<s[po-1];
}

int main(){

    string a;
    cin>>a;
    stringReverse(a,1);
    cout<<endl;

    return 0;
}