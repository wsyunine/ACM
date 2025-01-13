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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
int a[N],s[N];
int m,v,res=0;

signed main(){

    read(t);
    while(t--){
        read(n),read(m),read(v);res=-1;
        for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
        stack<int> sta;
        
        int tmp=0;
        for(int i=n;i>=1;i--){
            tmp+=a[i];
            if(tmp>=v) sta.push(i),tmp=0;
            if(sta.size()==m) break;
        }

        if(sta.size()<m){
            cout<<-1<<endl;
            continue;
        }

        int pj=sta.top(),pi=1;
        int r=sta.size();

        if(r==m){
            res=max(res,s[pj-1]);
        }else if(r<m){
            int sp=0,op=0;
            for(int i=pi;i<pj;i++){
                op+=a[i];
                if(op>=v) op=0,sp++;
                if(sp+r==m) break;
            }
            if(sp+r<m){
                cout<<-1<<endl;
                continue;
            }
        }

        while(sta.size()){
            sta.pop();
            if(sta.size()) pj=sta.top();
            else pj=n+1;
            int lp=0;
            while(lp<v){
                lp+=a[pi];
                pi++;
            }
            if(pi<pj) res=max(res,s[pj-1]-s[pi-1]);
        }

        cout<<res<<endl;

    }

    return 0;
}