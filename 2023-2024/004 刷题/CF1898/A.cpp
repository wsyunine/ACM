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
int n,k;
string s;

int main(){

    read(t);
    while(t--){
        int sb=0;
        read(n),read(k);
        cin>>s;

        for(int i=0;i<n;i++) sb+=(s[i]=='B');

        if(sb==k){
            cout<<0<<endl;
        }else if(sb<k){
            for(int i=0;i<=n;i++){
                if(s[i]=='A') sb++;
                if(sb==k){
                    cout<<1<<endl;
                    cout<<i+1<<" "<<'B'<<endl;
                    break;
                }
            }
        }else{
            for(int i=0;i<=n;i++){
                if(s[i]=='B') sb--;
                if(sb==k){
                    cout<<1<<endl;
                    cout<<i+1<<" "<<'A'<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}