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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
ll a,b,c,d;
vector<pair<ll,ll>> cz;

int main(){

    read(n);
    while(n--){
        cz.clear();
        read(a),read(b),read(c),read(d);
        ll op=c*d;
        if(a*b<c*d){
            cout<<-1<<endl;
            continue;
        }
        if(a!=1){
            cz.push_back({1,a});
            b=b*a;
        }
        int id=0,pos=2;
        while(op<=b/2){
            if(b==2){id=1;break;}
            cz.push_back({pos,b/2+1});
            a=b/2+1;b=1;
            if(pos==1) pos=2;
            else pos=1;
            if(op>a/2) break;
            if(a==2){id=1;break;}
            cz.push_back({pos,a/2+1});
            b=a/2+1;a=1;
            if(pos==1) pos=2;
            else pos=1;
        }
        if(id){
            cout<<-1<<endl;
            continue;
        }
        cz.push_back({pos,op});
        if(pos==1) pos=2;
        else pos=1;
        if(pos==1){
            cz.push_back({1,d});
        }else{
            cz.push_back({2,c});
        }

        printf("%zu\n",cz.size());
        for(auto i:cz){
            printf("%lld %lld\n",i.first,i.second);
        }
    }

    return 0;
}