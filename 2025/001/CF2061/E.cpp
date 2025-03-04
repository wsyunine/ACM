
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <thread>
#include <vector>
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

struct node{
    int c,aa;

    node(int c,int aa): c(c),aa(aa){}
};

struct cmp{
    bool operator()(const node& a,const node& b){
        return a.c<b.c;
    }
};

priority_queue<node,vector<node>,cmp> q;
int n,m,k;
int a[N],b[N],num[N][11],sum[10000],p[10000];

void solve() {

    while(q.size()) q.pop();
    read(n),read(m),read(k);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int j=1;j<=m;j++) read(b[j]);

    for(int i=1;i<=n;i++){
        num[i][0]=a[i];
        for(int j=1;j<=m;j++){
            num[i][j]=a[i];
        }
    }

    for(int i=1;i<(1<<m);i++){
        sum[i]=(1ll<<31ll)-1ll;p[i]=0;
        for(int j=1;j<=m;j++){
            if((i>>(j-1))&1) sum[i]&=b[j],p[i]++;
        }
    }

    for(int i=1;i<=n;i++){
        num[i][0]=a[i];
        for(int j=1;j<(1<<m);j++){
            num[i][p[j]]=min(num[i][p[j]],sum[j]&a[i]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            q.push(node(num[i][j-1]-num[i][j],i));
        }
    }

    while(k--){
        node s=q.top();
        q.pop();
        // cout<<s.aa<<" "<<s.c<<endl;
        a[s.aa]=a[s.aa]-s.c;
    }

    int res=0;
    for(int i=1;i<=n;i++){
        res+=a[i];
    }

    cout<<res<<endl;

}

signed main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
