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
#define ll long long
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

int t;
ll n;
int a[N];
unordered_map<int,int> mapp;
ll res=0;

void solve(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    res=n*(n+1ll)/2ll;

    for(int i=1;i<=10;i++){
        mapp.clear();
        int tmp=0,tmp1=0,op=1;
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                if(mapp[0]==0) mapp[0]++;
                while(op<j){
                    if(a[op]<=i) tmp1--;
                    else tmp1++;
                    mapp[tmp1]++;
                    op++;
                }
            }
            if(a[j]<=i) tmp--;
            else tmp++;
            // if(i==2) cout<<tmp<<mapp[0]<<endl;
            res-=(ll)mapp[tmp];
        }
        // cout<<endl;
    }

    cout<<res<<endl;
}

int main(){

    read(t);
    while(t--){
        solve();
    }

    return 0;
}
