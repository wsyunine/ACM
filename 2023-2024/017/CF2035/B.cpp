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
int k;


int main(){

    read(t);
    while(t--){
        read(n),read(k);

        if(n==1){
            cout<<"1\n1"<<endl;
            continue;
        }

        if(n==k){
            cout<<-1<<endl;
            continue;
        }else if(k==1){
            cout<<-1<<endl;
            continue;
        }

        if(k%2){
            cout<<3<<endl;
            cout<<1<<" "<<k-1<<" "<<k+2<<endl;
        }else{
            cout<<3<<endl;
            cout<<1<<" "<<k<<" "<<k+1<<endl;
        }
    }

    return 0;
}