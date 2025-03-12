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
int n,k;
int a[N];
int b[N];
vector<pair<int,int>> s;

void solve() {
    read(n);read(k);
    s.clear();
    for(int i=1;i<=n;i++) read(a[i]),s.push_back({a[i],1});
    for(int i=1;i<=n;i++) read(b[i]),s.push_back({b[i],-1});

    int tmp=0,s1=n,s2=0,s3=0,res=0;
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(tmp<=k) res=max(res,s[i].first*(s1+s2));
        tmp+=s[i].second;
        if(s[i].second==1) s1--,s2++;
        else s2--,s3++;
        while(i<s.size()-1&&s[i+1].first==s[i].first){
            i++;
            tmp+=s[i].second;
            if(s[i].second==1) s1--,s2++;
            else s2--,s3++;
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