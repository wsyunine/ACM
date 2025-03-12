#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
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
const int Mod=998244353;

int T;
int n;
int a[N],res=0;

void solve() {
    read(n);res=0;
    for(int i=1;i<=n;i++) read(a[i]);

    int tmp=0,s1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) tmp++,s1++;
        else if(a[i]==2){
            (tmp*=2ll)%=Mod;
        }else if(a[i]==3){
            (res+=tmp)%=Mod;
            res=(res-s1+Mod)%Mod;
        }
    }

    cout<<res<<endl;
}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}