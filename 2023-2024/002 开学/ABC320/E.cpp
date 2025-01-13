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
#define N 400010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

struct node{
    ll tim;
    bool is;
    int num;
};

ll n,m;
int g[N];
ll cnt[N],v[N];
vector<node> s;
priority_queue<int,vector<int>,greater<int> > q;

bool cmp(node a,node b){
    
    if(a.tim!=b.tim) return a.tim<b.tim;
    if(a.is!=b.is){
        return a.is==1;
    }
    return a.num<b.num;

}

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++) q.push(i);
    for(int i=1;i<=m;i++) g[i]=-1;

    for(int i=1;i<=m;i++){
        ll a,b,c;
        read(a),read(b),read(c);
        node op1,op2;
        op1.tim=a,op2.tim=a+c;
        op1.is=0,op2.is=1;
        op1.num=op2.num=i;
        v[i]=b;
        s.push_back(op1);
        s.push_back(op2);
    }

    sort(s.begin(),s.end(),cmp);

    int len=s.size();

    for(int i=0;i<len;i++){
        // cout<<" "<<s[i].tim<<" "<<q.top()<<endl;
        if(s[i].is==0){
            if(q.empty()) continue;
            g[s[i].num]=q.top();
            cnt[q.top()]+=v[s[i].num];
            q.pop();
        }else{
            //it is possible that no one went out at that time
            if(g[s[i].num]!=-1) q.push(g[s[i].num]);
        }
    }

    for(int i=1;i<=n;i++) cout<<cnt[i]<<endl;

    return 0;
}