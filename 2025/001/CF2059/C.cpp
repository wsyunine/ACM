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
int mapp[310][310],sum[310];

void solve() {
    read(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            read(mapp[i][j]);
        }
        sum[i]=0;
        for(int j=n;j>=1;j--){
            if(mapp[i][j]==1) sum[i]++;
            else break;
        }
    }

    int tmp=1;
    sort(sum+1,sum+1+n);

    for(int i=1;i<=n;i++){
        if(sum[i]>=tmp) tmp++;
    }
    if(tmp==n+1) tmp--;
    cout<<tmp<<endl;
    
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}