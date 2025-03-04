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
#include<unordered_map>
using namespace std;
#define N 500010
#define int long long
template <typename T> inline void read(T& x) {
    x = 0;
    bool flg = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            flg = 1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    if (flg)
        x = -x;
}

int n,m;
int t;
int a[N],b[N],sa=0,sb=0;
priority_queue<int> q1,q2;

void solve(){
    read(n);read(m);sa=sb=0;
    while(q1.size()) q1.pop();
    while(q2.size()) q2.pop();
    for(int i=1;i<=n;i++) read(a[i]),sa+=a[i],q1.push(a[i]);
    for(int i=1;i<=m;i++) read(b[i]),sb+=b[i],q2.push(b[i]);

    if(sa!=sb){
        cout<<"No"<<endl;
        return;
    }

    while(q1.size()&&q2.size()){
        // cerr<<q1.top()<<" "<<q2.top()<<endl;
        if(q2.top()==q1.top()){
            q1.pop();
            q2.pop();
        }else if(q2.top()>q1.top()){
            int st=q2.top();
            q2.pop();
            q2.push(st/2);
            q2.push(st-st/2);
        }else{
            cout<<"No"<<endl;
            return;
        }
    }

    if(q1.size()||q2.size()){
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
}

signed main(){
    read(t);
    while(t--){
        solve();
    }

    return 0;
}
