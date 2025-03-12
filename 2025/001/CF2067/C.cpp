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
int n;

void solve() {
    read(n);

    queue<pair<int,int>> q;
    q.push({n,0});
    while(q.size()){
        auto t=q.front();
        q.pop();
        int op=t.first;
        while(op){
            if(op%10==7){
                cout<<t.first<<" ";
                cout<<t.second<<endl;
                return;
            }
            op/=10;
        }
        for(int i=10;i<=10;i*=10){
            q.push({t.first+i-1,t.second+1});
        }
    }
}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}