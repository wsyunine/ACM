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
int t;
int m;

int main(){

    read(t);
    while(t--){
        read(n),read(m);

        if(m>n-3){cout<<-1<<endl;continue;}
        if(n==4){
            if(m==0) cout<<"3 1 2 4"<<endl;
            if(m==1) cout<<"1 2 3 4"<<endl;
            continue;
        }
        if(n==3){
            cout<<"1 2 3"<<endl;
            continue;
        }
        if(n==5){
            if(m==0) cout<<"4 1 2 3 5"<<endl;
            if(m==1) cout<<"5 1 2 3 4"<<endl;
            if(m==2) cout<<"1 2 3 4 5"<<endl;
            continue;
        }
        if(m==0){
            if(n%3) cout<<n/3*3+1<<" ";
            for(int i=n/3;i>=1;i--){
                cout<<i<<" "<<i+n/3<<" "<<i+n/3+n/3<<" ";
            }
            if(n%3==2) cout<<n<<endl;
            continue;
        }
        if(m==n-3){
            for(int i=1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
            continue;
        }
        int op=n-m;
        int s=0;
        vector<int> res(n+1);
        if(op%3) res[++s]=op/3*3+1;
        for(int i=op/3;i>=1;i--){
            res[++s]=i;
            res[++s]=i+op/3;
            res[++s]=i+op/3+op/3;
        }
        if(op%3==2) res[++s]=op/3*3+2;
        for(int i=op+1;i<=n;i++) res[++s]=i;
        if(op%3==1) swap(res[1],res[op+1]);
        for(int i=1;i<=n;i++) cout<<res[i]<<" ";
        cout<<endl;

    }

    return 0;
}