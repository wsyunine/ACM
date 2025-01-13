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

int n,a,b;
int t;
string str;

int main(){

    read(t);
    while(t--){
        read(n);read(a),read(b);
        cin>>str;
        int idea=0,x=0,y=0;
        for(int i=1;i<=100;i++){
            if(x==a&&y==b){idea=1;break;}
            for(int j=0;j<n;j++){
                if(str[j]=='N') y++;
                if(str[j]=='E') x++;
                if(str[j]=='S') y--;
                if(str[j]=='W') x--;
                if(x==a&&y==b){idea=1;break;}
            }
            if(idea) break;
        }
        if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}