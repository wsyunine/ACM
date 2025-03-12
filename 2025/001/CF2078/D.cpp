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
vector<pair<bool,int>> ope[2];
int res=0;
int suf[2][33],f[33][2];

void dfs(int x,int l,int r){
    if(x>n){
        res=max(res,l+r);
        return;
    }
    int op=0;
    if(ope[0][x].first==0){
        op+=ope[0][x].second;
    }else{
        op+=(ope[0][x].second-1)*l;
    }
    if(ope[1][x].first==0){
        op+=ope[1][x].second;
    }else{
        op+=(ope[1][x].second-1)*r;
    }

    if(f[x+1][0]>f[x+1][1]){
        dfs(x+1,l+op,r);
    }else{
        dfs(x+1,l,r+op);
    }
    
}

void solve() {
    read(n);
    res=0;
    ope[0].clear();
    ope[1].clear();
    ope[0].push_back({0,0});
    ope[1].push_back({0,0});
    for(int i=1;i<=n+1;i++) suf[0][i]=suf[1][i]=0;
    for(int i=1;i<=n;i++){
        char s;
        int p;
        cin>>s;
        read(p);
        if(s=='+'){
            ope[0].push_back({0,p});
        }else{
            ope[0].push_back({1,p});
        }
        cin>>s;
        read(p);
        if(s=='+'){
            ope[1].push_back({0,p});
        }else{
            ope[1].push_back({1,p});
        }
    }

    for(int i=1;i<=n;i++){
        int tmp[2]={0,0};
        for(int j=i;j<=n;j++){
            if(ope[0][j].first==1){
                tmp[0]+=ope[0][j].second-1;
            }
            if(ope[1][j].first==1){
                tmp[1]+=ope[1][j].second-1;
            }
        }
        suf[0][i]=tmp[0];
        suf[1][i]=tmp[1];
        // cout<<suf[1][i]<<" ";
    }

    f[n+1][0]=f[n+1][1]=0;
    f[n][0]=1+suf[0][n];
    f[n][1]=1+suf[1][n];
    for(int i=n-1;i>=1;i--){
        if(ope[0][i].first==1) f[i][0]=f[i+1][0]+max(f[i+1][0],f[i+1][1])*(ope[0][i].second-1);
        else f[i][0]=f[i+1][0];
        if(ope[1][i].first==1) f[i][1]=f[i+1][1]+max(f[i+1][0],f[i+1][1])*(ope[1][i].second-1);
        else f[i][1]=f[i+1][1];
    }

    // for(int i=1;i<=n;i++){
    //     cout<<f[i][0]<<" "<<f[i][1]<<endl;
    // }

    // cout<<endl;

    dfs(1,1,1);

    cout<<res<<endl;

}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}