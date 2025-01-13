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

int main(){

    read(n);
    cin>>s;

    for(int i=1;i<n;i++){
        int cnt=0;
        for(int j=0;i+j<n;j++){
            if(s[j]==s[i+j]) break;
            else cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}