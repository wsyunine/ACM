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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,a,b,ans=0x3f3f3f3f3f3f3f3f;
string s;

signed main(){

    read(n),read(a),read(b);
    cin>>s;
    for(int i=0;i<n;i++) s.push_back(s[i]);

    for(int i=0;i<n;i++){
        int tmp=i*a;
        for(int j=0;i+j<i+n-j;j++){
            if(s[i+j]!=s[i+n-j-1]) tmp+=b;
        }
        ans=min(ans,tmp);
    }

    cout<<ans<<endl;

    return 0;
}