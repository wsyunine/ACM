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

string a;

bool testPalindrome(string s,int po){
    int len=s.size();
    if(po>len/2) return 1;
    return ((s[po-1]==s[len-po])&&testPalindrome(s,po+1));
}

int main(){

    cin>>a;
    cout<<testPalindrome(a,1)<<endl;

    return 0;
}