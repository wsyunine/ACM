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
int a[N],b[N];
unordered_map<int,int> mapp;

void solve() {
    read(n);
    int tmp=0;
    mapp.clear();
    for(int i=1;i<=n;i++) read(a[i]),mapp[a[i]]++;
    tmp+=mapp.size();
    mapp.clear();
    for(int i=1;i<=n;i++) read(b[i]),mapp[b[i]]++;
    tmp+=mapp.size();
    if(tmp-1>=3) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}