#include<bits/stdc++.h>
using namespace std;
#define N 1000010
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
int a[N];
int e[N],ne[N],h[N],idx;
int f[N];
int res[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x,int fa){
    f[x]=fa;
    vector<int> s;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
    }
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        s.push_back(a[j]);
    }
    sort(s.begin(),s.end());
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            res[s[i]]=1;
        }
    }
}

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]),res[i]=0,h[i]=-1;

    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b);
        add(b,a);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        if(a[f[i]]==a[i]||a[f[f[i]]]==a[i]){
            res[a[i]]=1;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<res[i];
    }
    cout<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}