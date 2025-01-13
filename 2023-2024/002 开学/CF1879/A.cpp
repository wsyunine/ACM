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
int s[N],e[N];

int main(){

    read(t);
    while(t--){
        read(n);
        bool idea=0;
        for(int i=1;i<=n;i++){
            read(s[i]),read(e[i]);
        }
        for(int i=2;i<=n;i++){
            if(s[i]>=s[1]&&e[i]>=e[1]){
                cout<<-1<<endl;
                idea=1;
                break;
            }
        }
        
        if(idea) continue;

        cout<<s[1]<<endl;
    }

    return 0;
}