#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
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
ll mod=998244353;

template <typename T1, typename T2>
struct std::hash<std::pair<T1, T2>> {
    size_t operator()(const std::pair<T1, T2>& p) const {
        size_t h1 = std::hash<T1>{}(p.first);
        size_t h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int T;
unordered_map<pair<ll,ll>,int> mapp;
string str;
int a[N],n;
ll hs[N],jc[N];
ll hs1[N],jc1[N];
ll base=13331,base1=57;

void init(){
    jc[n]=1;
    for(int i=n-1;i>=1;i--){
        jc[i]=jc[i+1]*base%mod;
    }
    hs[0]=0;
    for(int i=1;i<=n;i++){
        hs[i]=(hs[i-1]*base+a[i])%mod;
    }
    jc1[n]=1;
    for(int i=n-1;i>=1;i--){
        jc1[i]=jc1[i+1]*base1%mod;
    }
    hs1[0]=0;
    for(int i=1;i<=n;i++){
        hs1[i]=(hs1[i-1]*base1+a[i])%mod;
    }
}

ll query(int l,int r){
    return (hs[r]-hs[l-1]*jc[n-r+l-1]%mod+mod)%mod;
}

ll query1(int l,int r){
    return (hs1[r]-hs1[l-1]*jc1[n-r+l-1]%mod+mod)%mod;
}

void solve() {
    cin>>str;
    n=str.size();
    ll res=0;
    str=' '+str;
    for(int i=1;i<=n;i++){
        a[i]=(str[i]=='0'?0:1);
    }
    init();

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            //换两端
            ll op1=0,op11,op2=0,op21,op3=0,op31;
            op1=(hs[n]-a[i]*jc[i]%mod+(a[i]^1)*jc[i]+mod)%mod;
            op1=(op1-a[j]*jc[j]%mod+(a[j]^1)*jc[j]+mod)%mod;
            op11=(hs1[n]-a[i]*jc1[i]%mod+(a[i]^1)*jc1[i]+mod)%mod;
            op11=(op11-a[j]*jc1[j]%mod+(a[j]^1)*jc1[j]+mod)%mod;
            mapp[{op1,op11}]=1;
            
            //左增右删
            ll op=query(i+1,j),opp=query1(i+1,j),p=query(i,j),p1=query1(i,j);
            op2=(hs[n]-p*jc[j]%mod+mod)%mod;
            op2=(op2+op*jc[j-1])%mod;
            op21=(hs1[n]-p1*jc1[j]%mod+mod)%mod;
            op21=(op21+opp*jc1[j-1])%mod;
            mapp[{op2,op21}]=1;
            op2=(op2+jc[j])%mod;
            op21=(op21+jc1[j])%mod;
            mapp[{op2,op21}]=1;
            
            //左删右增
            op=query(i,j-1);opp=query1(i,j-1);
            op3=(hs[n]-p*jc[j]%mod+mod)%mod;
            op3=(op3+op*jc[j])%mod;
            op31=(hs1[n]-p1*jc1[j]%mod+mod)%mod;
            op31=(op31+opp*jc1[j])%mod;
            mapp[{op3,op31}]=1;
            op3=(op3+jc[i])%mod;
            op31=(op31+jc1[i])%mod;
            mapp[{op3,op31}]=1;
        }
    }

    for(int i=1;i<=n;i++){
        //去除一次得到的串
        int op1=0,op11;
        op1=(hs[n]-a[i]*jc[i]%mod+(a[i]^1)*jc[i]+mod)%mod;
        op11=(hs1[n]-a[i]*jc1[i]%mod+(a[i]^1)*jc1[i]+mod)%mod;
        mapp.erase({op1,op11});
    }
    mapp.erase({hs[n],hs1[n]});

    cout<<mapp.size()<<endl;
}

signed main() {
    T=1;
    while(T--) {
        solve();
    }
    return 0;
}