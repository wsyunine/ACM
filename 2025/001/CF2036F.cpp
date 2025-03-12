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

int T;
int l,r,opi,k;

void solve() {
    int res=0,del=0;
    read(l),read(r),read(opi),read(k);

    res=(r-l+1);
    int ip=(1ll<<opi);
    int ll=l/ip;
    if(l%ip>k) ll++;
    int rr=r/ip;
    if(r%ip<k) rr--;
    if(ll>rr){
        cout<<res<<endl;
        return;
    } 

}

signed main() {

    int tmp=0;
    for(int i=1;i<=10;i++){
        tmp^=i;
        cerr<<tmp<<" ";
    }
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}