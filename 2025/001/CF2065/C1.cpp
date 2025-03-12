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
int n,m;
int a[N];
int b[N];

void solve() {
    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++) read(b[i]);

    int idea=1;
    a[0]=0xf3f3f3f3;
    for(int i=1;i<=n;i++){
        a[i]=min(a[i],b[1]-a[i]);
        if(a[i]<a[i-1]){
            a[i]=max(a[i],b[1]-a[i]);
            if(a[i]<a[i-1]){idea=0;break;}
        }
    }

    if(idea) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}