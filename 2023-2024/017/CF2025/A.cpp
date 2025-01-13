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

int n;
string a,b;

int main(){

    read(n);
    while(n--){
        cin>>a>>b;
        int la=a.length(),lb=b.length();

        int ans=0;
        for(int i=1;i<=min(la,lb);i++){
            if(a[i-1]==b[i-1]) ans++;
            else break;
        }

        cout<<(ans?la+lb-ans+1:la+lb)<<endl;
    }

    return 0;
}