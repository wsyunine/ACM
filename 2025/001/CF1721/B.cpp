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
int vis[1010][1010];
int n,m,sx,sy,d;

void solve() {
    read(n),read(m);
    read(sx),read(sy);
    read(d);

    int idea=1;
    for(int i=1;i<=n;i++) if(abs(i-sx)+abs(1-sy)<=d) idea=0;
    for(int i=1;i<=m;i++) if(abs(n-sx)+abs(i-sy)<=d) idea=0;

    if(idea){
        cout<<n+m-2<<endl;
        return;
    } 

    idea=1;
    for(int i=1;i<=m;i++) if(abs(1-sx)+abs(i-sy)<=d) idea=0;
    for(int i=1;i<=n;i++) if(abs(i-sx)+abs(m-sy)<=d) idea=0;

    if(idea){
        cout<<n+m-2<<endl;
        return;
    }
    
    cout<<-1<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}