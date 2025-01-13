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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
int mapp[100][100];

int main(){

    read(t);
    while(t--){
        read(n);

        if(n==1){
            cout<<1<<endl;
            continue;
        }

        cout<<169;
        for(int i=4;i<=n;i++) cout<<0;
        cout<<endl;
        cout<<196;
        for(int i=4;i<=n;i++) cout<<0;
        cout<<endl;
        cout<<961;
        for(int i=4;i<=n;i++) cout<<0;
        cout<<endl;

        for(int i=1;i<n/2;i++){
            cout<<9;
            for(int j=1;j<=i;j++) cout<<0;
            cout<<6;
            for(int j=1;j<=i;j++) cout<<0;
            cout<<1;
            for(int j=2*i+3;j<n;j++) cout<<0;
            cout<<endl;
            cout<<1;
            for(int j=1;j<=i;j++) cout<<0;
            cout<<6;
            for(int j=1;j<=i;j++) cout<<0;
            cout<<9;
            for(int j=2*i+3;j<n;j++) cout<<0;
            cout<<endl;
        }
    }

    return 0;
}