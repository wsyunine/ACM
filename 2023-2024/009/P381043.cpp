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

int t;
int n,m;
int e[N],ne[N],h[N],idx;
int d[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){

    read(t);
    while(t--){
        memset(h,-1,sizeof h);idx=0;
        vector<int> res;
        read(n),read(m);
        for(int i=1;i<=n;i++) d[i]=0;

        for(int i=1;i<=m;i++){
            int a,b;
            read(a),read(b);
            add(b,a);d[a]++;
        }

        priority_queue<int> q;
        for(int i=n;i>=1;i--) if(!d[i]) q.push(i);

        while(q.size()){
            int op=q.top();
            q.pop();
            for(int i=h[op];~i;i=ne[i]){
                int j=e[i];
                if(--d[j]==0) q.push(j);
            }
            res.push_back(op);
        } 

        reverse(res.begin(),res.end());

        if(res.size()<n){
            cout<<"Impossible!"<<endl;
        }else{
            for(auto i:res) cout<<i<<" ";
            cout<<endl;
        }
    }

    return 0;
}