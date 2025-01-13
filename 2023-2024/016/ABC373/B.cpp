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

int pos[100];
string s;

int main(){

    cin>>s;
    for(int i=0;i<26;i++){
        pos[s[i]-'A']=i;
    }

    int cnt=0,p=pos[0];
    for(int i=1;i<26;i++){
        cnt+=abs(p-pos[i]);
        p=pos[i];
    }
    cout<<cnt<<endl;

    return 0;
}