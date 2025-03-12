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
int n;
int b[N];

void solve() {
    read(n);
    for(int i=2;i<n;i++) read(b[i]);

    for(int i=3;i<n-1;i++){
        if(b[i]==0&&b[i-1]==1&&b[i+1]==1){
            cout<<"No"<<endl;
            return ;
        }
    }

    cout<<"Yes"<<endl;
    return;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}