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
int n,m,k;

void solve() {
    read(n),read(m),read(k);

    if(abs(n-m)>k){
        cout<<-1<<endl;
        return;
    }

    if(k>n&&k>m){
        cout<<-1<<endl;
        return;
    }

    if(n>=m){
        for(int i=1;i<=k;i++) cout<<0,n--;
        for(int i=1;i<=n;i++) cout<<10,m--;
        while(m--) cout<<1;
        cout<<endl;
    }else{
        for(int i=1;i<=k;i++) cout<<1,m--;
        for(int i=1;i<=m;i++) cout<<0<<1,n--;
        while(n--) cout<<0;
        cout<<endl;
    }

}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}