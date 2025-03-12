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
int n,m;

void solve() {
    read(n),read(m);
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    vector<pair<int,int>> b(n+1,{0,0});

    for(int i=1;i<=n;i++){
        b[i].second=i;
        for(int j=1;j<=m;j++){
            read(a[i][j]);
            b[i].first+=a[i][j];
        }
    }

    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    int res=0,tmp=0;
    for(int i=0;i<n;i++){
        int k=b[i].second;
        for(int j=1;j<=m;j++){
            tmp+=a[k][j];
            res+=tmp;
        }
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