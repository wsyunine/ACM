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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t,mx=0,s=0;
unordered_map<int,int> mapp;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(t);
    while(t--){
        read(n);mx=0;s=0;
        for(int i=1;i<=n;i++){
            int op;
            read(op);
            mapp[op]=1;
            mx=max(mx,op);
        }

        for(int i=1;i<=mx;i++){
            int sop=-1;
            for(int j=i;j<=mx;j+=i){
                if(sop==-1&&mapp[j]){
                    sop=j;
                }else if(mapp[j]){
                    sop=gcd(sop,j);
                }
            }
            if(sop==i) s++;
        }

        // cout<<s<<endl;

        if((s-n)%2) cout<<"dXqwq"<<endl;
        else cout<<"Haitang"<<endl;

        mapp.clear();
    }

    return 0;
}