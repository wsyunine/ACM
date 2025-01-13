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
string a[10]={"abc","acb","bac","cba"};

int main(){

    read(t);
    while(t--){
        string s;
        int id=0;
        cin>>s;
        for(int i=0;i<=3;i++){
            if(s==a[i]){
                cout<<"YES"<<endl;
                id=1;
                break;
            }
        }
        if(!id) cout<<"NO"<<endl;
    }

    return 0;
}