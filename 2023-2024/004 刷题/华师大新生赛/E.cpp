#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,a[N];
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int>> q2;

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    q1.push(a[1]);
    cout<<a[1]<<endl;
    for(int i=2;i<=n;i++){
        if((i-1)%2){
            if(a[i]<q1.top()){
                q2.push(q1.top());
                q1.pop();
                q1.push(a[i]);
            }else{
                q2.push(a[i]);
            }
        }else{
            if(a[i]<=q2.top()){
                q1.push(a[i]);
            }else{
                q1.push(q2.top());
                q2.pop();
                q2.push(a[i]);
            }
        }
        cout<<q1.top()<<endl;
    }

    return 0;
}