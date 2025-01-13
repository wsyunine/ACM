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

int n;
int d[N];

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        int a,b;
        read(a),read(b);
        if(a>b) swap(a,b);
        d[a]=b,d[b]=a;
    }

    stack<int> stk;

    for(int i=1;i<=2*n;i++){
        if(d[i]>i) stk.push(i);
        else{
            if(stk.top()!=d[i]){
                cout<<"Yes"<<endl;
                return 0;
            }else stk.pop();
        }
    }

    cout<<"No"<<endl;

    return 0;
}