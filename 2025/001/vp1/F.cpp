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
int n,q;
int t[N];

void solve() {
    read(n),read(q);
    int res=0;
    for(int i=1;i<=q;i++){
        int opt,l,r;
        read(l),read(r),read(opt);
        int tmp=(r-l)*opt;
        res^=(tmp&1);
        if(res) cout<<"huai"<<endl;
        else cout<<"hao"<<endl;
    }
}

int main() {
    T=1;
    while(T--) {
        solve();
    }
    return 0;
}