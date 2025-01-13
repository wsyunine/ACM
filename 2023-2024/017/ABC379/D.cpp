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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int m,tmp=0;
priority_queue<int> q;

signed main(){

    read(n);
    while(n--){
        int opt;
        int t,h;
        read(opt);
        if(opt==1){
            q.push(-tmp);
        }else if(opt==2){
            read(t);
            tmp+=t;
        }else if(opt==3){
            read(h);
            int res=0;
            while(q.size()&&q.top()+tmp>=h) q.pop(),res++;
            printf("%lld\n",res);
        }
    }

    return 0;
}