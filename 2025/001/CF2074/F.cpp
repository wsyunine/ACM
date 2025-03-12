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
int l1,l2,r1,r2;
int res=0;

void calc(int x1,int x2,int y1,int y2){

    int opx1,opx2,opy1,opy2,tmp;
    for(int i=20;i>=0;i--){
        tmp=(1<<i);
        opx1=(x1-1)/tmp+1,opx2=x2/tmp;
        if(x1==0) opx1=0;
        if(opx1>=opx2) continue;
        opy1=(y1-1)/tmp+1,opy2=y2/tmp;
        if(y1==0) opy1=0;
        if(opy1>=opy2) continue;
        break;
    }
    // cout<<tmp<<endl;
    res+=(opx2-opx1)*(opy2-opy1);
    opx1=opx1*tmp;
    opx2=opx2*tmp;
    opy1=opy1*tmp;
    opy2=opy2*tmp;
    if(x1<opx1) calc(x1,opx1,y1,y2);
    if(x2>opx2) calc(opx2,x2,y1,y2);
    if(opy1>y1) calc(opx1,opx2,y1,opy1);
    if(opy2<y2) calc(opx1,opx2,opy2,y2);

}

void solve() {
    read(l1),read(r1),read(l2),read(r2);

    res=0;
    calc(l1,r1,l2,r2);

    cout<<res<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}