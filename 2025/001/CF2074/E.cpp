#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n;

struct node{
    int a,b,c;
    node(int a,int b,int c): a(a),b(b),c(c){}
};

void solve() {
    read(n);
    if(n==3){
        cout<<"! 1 2 3"<<endl;
        return;
    }

    queue<node> q;

    q.push(node(1,2,3));
    while(q.size()){
        node x=q.front();
        q.pop();
        cout<<"? "<<x.a<<" "<<x.b<<" "<<x.c<<endl;

        int y;
        cin>>y;
        if(y==0){
            cout<<"! "<<x.a<<" "<<x.b<<" "<<x.c<<endl;
            return;
        }else{
            q.push(node(x.a,x.b,y));
            q.push(node(x.c,x.b,y));
            q.push(node(x.a,x.c,y));
        }
    }
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}