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
int t;
string s;
int prex[N],pred[N];

int main(){

    read(t);
    while(t--){
        read(n);
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n;i++){
            prex[i]=prex[i-1];
            pred[i]=pred[i-1];
            if(s[i]=='<') prex[i]++;
            else if(s[i]=='>') pred[i]++;
        }

        int xx=0,dd=0;
        for(int i=1;i<=n;i++){
            int ll=0,rr=0;
            if(s[i]=='<'){
                ll=dd;
                int pot=upper_bound(prex+1,prex+1+n,ll)-prex;
            }else{

            }
        }
    }

    return 0;
}