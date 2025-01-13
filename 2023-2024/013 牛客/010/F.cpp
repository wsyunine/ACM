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
#include<unordered_map>
using namespace std;
#define N 1000010
#define LD long double
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const LD eps=1e-9;
inline int dcmp(LD a){return a<-eps?-1:(a>eps?1:0);}
inline LD Abs(LD a){return a*dcmp(a);}

pair<int,int> po[N];
int n;
int mapp[N];
unordered_map<long long,int> s;

int main(){

    read(n);
    for(int i=1;i<=n*n;i++){
        read(po[i].first),read(po[i].second);
    }

    mapp[1]=1;
    for(int i=2;i<=n*n;i++){
        s.clear();
        int id=1,hzd=0;
        for(int j=1;j<i;j++){
            long long sl;
            if(mapp[j]){
                if(po[i].first-po[j].first!=0){
                    sl=((double)(po[i].second-po[j].second)/((double)(po[i].first-po[j].first)))*10000;
                    if(s[sl]){id=0;break;}
                    s[sl]=1;
                }else{
                    if(hzd){id=0;break;}
                    hzd=1;
                }
            }
        }
        if(id) mapp[i]=1;
    }

    for(int i=1;i<=n*n;i++) cout<<mapp[i];
    cout<<endl;

    return 0;
}