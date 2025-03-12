
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

int t;
int n;
string s;
int st[1300010];

void add(int x,int y){
    x+=3*n+1;
    for(;x<=4*n+2;x+=x&(-x)) st[x]+=y;
}

ll query(int x){
    ll res=0;
    x+=3*n+1;
    if(x<=0) return 0;
    for(;x;x-=x&(-x)) res+=(ll)st[x];
    return res;
}

void solve()
{
    read(n);
    cin >> s;
    s = ' ' + s;
    add(0,1);
    int tmp=0;
    ll res=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0') tmp++;
        else tmp-=3;
        res+=query(tmp-2);
        res+=(query(tmp+1)-query(tmp));
        add(tmp,1);
    }
    cout<<res<<endl;
}

int main()
{
    t=1;
    while(t--) {
        solve();
    }

    return 0;
}
