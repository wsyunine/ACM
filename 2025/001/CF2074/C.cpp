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
int x;

void solve() {
    read(x);
    int op0=0,res=0,op1=0;
    for(int i=1;i<=x;i<<=1){
        if((x&i)&&op1==0){
            op1=1;
            res+=i;
        }else if(!op0&&((x&i)==0)){
            op0=1;
            res+=i;
        }
    }
    if(res<x&&op0&&op1) cout<<res<<endl;
    else cout<<-1<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}