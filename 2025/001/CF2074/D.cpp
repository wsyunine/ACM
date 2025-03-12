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
int m;
int x[N];
int r[N];
unordered_map<int,int> mapp;

void solve() {
    mapp.clear();
    read(n),read(m);
    for(int i=1;i<=n;i++) read(x[i]);
    for(int i=1;i<=n;i++) read(r[i]);

    for(int i=1;i<=n;i++){
        for(int j=x[i]-r[i];j<=x[i]+r[i];j++){
            double p=abs(j-x[i]),q=r[i]; 
            mapp[j]=max((int)sqrt(q*q-p*p),mapp[j]);
        }
    }

    int res=0;
    for(auto i:mapp){
        res+=i.second*2+1;
    }
    cout<<res<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}