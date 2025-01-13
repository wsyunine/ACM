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

int t;
int n;

int main(){

    read(t);
    while(t--){
        read(n);
        if(n%2==0) cout<<-1<<endl;
        else{
            cout<<n<<" ";
            for(int i=n-1;i>=2;i-=2){
                cout<<i-1<<" "<<i<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}