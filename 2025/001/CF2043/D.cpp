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
int l,r,G;
int ll,rr;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void solve() {
    read(l),read(r),read(G);
    ll=(l-1)/G+1;
    rr=r/G;

    if(ll>rr){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    if(ll==rr){
        if(ll==1){
            cout<<G<<" "<<G<<endl;
            return;
        }else{
            cout<<-1<<" "<<-1<<endl;
            return;
        }
    }

    int resl,resr,res=0;
    for(int i=ll;i<=min(ll+5,rr);i++){
        for(int j=max(rr-16,i);j<=rr;j++){
            if(gcd(i,j)==1&&res<j-i){res=j-i,resl=i,resr=j;}
        }
    }

    // for(int i=ll;i<=min(rr,opr);i++){
    //     int g=gcd(ll,rr);
    //     int tp=rr-rr/g;
    //     if(tp-ll+1>res){
    //         resl=ll;
    //         resr=tp;
    //         res=tp-ll+1;
    //     }
    //     opr=rr-res;
    // }

    cout<<resl*G<<" "<<resr*G<<endl;

}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}