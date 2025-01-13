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
int cntt=0,cntd=0;

int main(){

    cin>>s;

    int len=s.size();

    for(int i=0;i<len;i++){
        if(s[i]=='T') cntt++;
        else if(s[i]=='D') cntd++;
    }

    if(cntd>=3) cout<<"DRX"<<endl;
    else cout<<"T1"<<endl;

    return 0;
}