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

struct node{
    int num,op;
};

bool cmp(node a,node b){
    return a.num<b.num;
}

int T;
int n;
node a[N],b[N];

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i].op),a[i].num=a[i].op;
    for(int i=1;i<=n;i++) read(b[i].op),b[i].num=b[i].op;
    
    int res=0;
    int opt=(1ll<<31ll)-1ll;
    for(int i=30;i>=0;i--){
        int opr=0;
        for(int j=1;j<=n;j++){
            a[j].num&=opt;
            b[j].num&=opt;
        }
        // for(int j=1;j<=n;j++) cout<<a[j].num<<" ";
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        reverse(b+1,b+1+n);
        opr=a[1].op^b[1].op;
        for(int j=2;j<=n;j++){
            opr&=(a[j].op^b[j].op);
        }
        if(((opr>>i)&1ll)==0) opt=opt^(1ll<<i);
        // cout<<((opr>>i)&1ll)<<" ";
        // cout<<opr<<endl;
        res=max(res,opr);
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
/*
1
8
28 14 12 27 10 8 27 27
5 23 17 2 21 19 6 22


1
13
28 12 15 14 2 28 10 10 4 25 19 5 15
23 11 16 17 9 23 1 9 19 22 12 18 8
*/