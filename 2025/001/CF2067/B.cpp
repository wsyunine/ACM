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
int a[N],mapp[N];

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n*2;i++) mapp[i]=0;

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        while(mapp[a[i]]==2) a[i]++;
        mapp[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(mapp[a[i]]!=2){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}