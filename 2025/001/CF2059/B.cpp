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
int n,k;
int a[N];

void solve() {
    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]);

    if(n==k){
        int tmp=1;
        for(int i=2;i<=n;i+=2){
            if(a[i]!=tmp){
                cout<<tmp<<endl;
                return;
            }
            tmp++;
        }
        cout<<tmp<<endl;
        return;
    }

    for(int i=n-(k-2);i>=2;i--){
        if(a[i]!=1){
            cout<<1<<endl;
            return;
        }
    }

    cout<<2<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}