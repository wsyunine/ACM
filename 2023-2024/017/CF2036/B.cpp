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

int t,n,k;
int a[N],b[N],res=0;
priority_queue<int> q;

int main(){

    read(t);
    while(t--){
        read(n),read(k);res=0;
        for(int i=1;i<=k;i++) b[i]=0;
        while(q.size()) q.pop();
        for(int i=1;i<=k;i++){
            int op1,op2;
            read(op1),read(op2);
            b[op1]+=op2;
        }

        for(int i=1;i<=k;i++){
            q.push(b[i]);
        }

        while(n--&&q.size()){
            res+=q.top();
            q.pop();
        }

        cout<<res<<endl;
    }

    return 0;
}