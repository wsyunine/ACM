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

int n,f[N];
struct node{
    int val;
    node* nxt_bro;
    node* son;
}p[N];

void add(node &a,node &b){//类似邻接表
    b.nxt_bro=a.son;
    a.son=&b;
}

int main(){

    read(n);//钦定1为根
    for(int i=1;i<=n;i++) p[i].val=i;
    for(int i=2;i<n;i++){//2~n的父亲
        read(f[i]);
        add(p[f[i]],p[i]);
    }

    //BFS
    queue<int> q;
    q.push(1);
    while(q.size()){
        int op=q.front();
        q.pop();
        cout<<op<<" ";//输出编号
        for(node *i=p[op].son;i!=nullptr;i=(*i).nxt_bro){//找儿子
            q.push((*i).val);
        }
    }
    cout<<endl;

    return 0;
}