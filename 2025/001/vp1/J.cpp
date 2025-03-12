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
int n,m;
int mapp[1010][1010];

void solve() {
    read(n),read(m);
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=1;j<=m;j++){
            mapp[i][j]=(str[j-1]=='0'?0:1);
        }
    }

    int idea=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            idea&=(mapp[i][j]==(i+j+1)%2);
        }
    }

    if(idea){
        cout<<0<<endl;
        return;
    }

    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mapp[i][j]!=(i+j)%2) res++;
        }
    }

    cout<<res<<endl;
}   

int main() {
    T=1;
    while(T--) {
        solve();
    }
    return 0;
}