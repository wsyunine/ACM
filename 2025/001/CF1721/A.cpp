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
char a[5];

void solve() {
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) return cout<<0<<endl,void();
    if(a[0]==a[1]&&a[1]!=a[2]&&a[2]==a[3]) return cout<<1<<endl,void();
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]!=a[3]) return cout<<1<<endl,void();
    if(a[0]==a[1]&&a[1]!=a[2]&&a[2]!=a[3]) return cout<<2<<endl,void();
    if(a[0]!=a[1]&&a[1]==a[2]&&a[2]==a[3]) return cout<<1<<endl,void();
    if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]==a[3]) return cout<<2<<endl,void();
    if(a[0]!=a[1]&&a[1]==a[2]&&a[2]!=a[3]) return cout<<2<<endl,void();
    if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]!=a[3]) return cout<<3<<endl,void();
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}