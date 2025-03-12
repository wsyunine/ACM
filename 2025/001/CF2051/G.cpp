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
int q;
vector<pair<int,bool>> ope;
int mapp[22][22],mxd[22];
int dp[1200000][21];

void solve() {
    read(n),read(q);
    ope.clear();
    ope.push_back({0,0});
    for(int i=1;i<=n;i++) mxd[i]=1;
    for(int i=1;i<=q;i++){
        int rk;
        char s;
        read(rk);
        cin>>s;
        if(s=='+') ope.push_back({rk,1}),mxd[rk]++;
        else ope.push_back({rk,0});
    }

    for(int i=1;i<=n;i++){
        int tmp=0;
        vector<int> sek(21,0);
        for(int j=1;j<=q;j++){
            if(ope[j].first==i){
                if(ope[j].second==0) tmp++;
            }else{
                if(ope[j].second==1){
                    if(tmp>sek[ope[j].first]) sek[ope[j].first]++;
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            mapp[j][i]=mxd[i]-sek[j];
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<mapp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<(1<<n);i++) for(int j=1;j<=n;j++) dp[i][j]=0x3f3f3f3f;
    for(int i=1;i<(1<<n);i++){
        // cout<<i<<": ";
        for(int j=1;j<=n;j++){
            if(((i>>(j-1))&1)==0) continue;
            int sp=(i^(1<<(j-1)));
            if(sp==0){dp[i][j]=mxd[j];continue;}
            for(int k=1;k<=n;k++){
                if(((sp>>(k-1))&1)==0) continue;
                dp[i][j]=min(dp[sp][k]+mapp[k][j],dp[i][j]);
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    int res=0x3f3f3f3f;
    for(int i=1;i<=n;i++) res=min(res,dp[(1<<n)-1][i]);
    cout<<res<<endl;
}

int main() {
    T=1;
    while(T--) {
        solve();
    }
    return 0;
}