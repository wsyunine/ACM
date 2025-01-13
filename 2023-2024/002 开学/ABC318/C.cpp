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

signed main(){

    int n,d,p,s=0,sp;
    cin>>n>>d>>p;
    vector<int> f(n+1);
    for(int i=1;i<=n;i++){
        cin>>f[i];s+=f[i];
    }

    sort(f.begin()+1,f.end());

    for(int i=n;i>=1;){
        sp=s;
        sp+=p;
        int t=d;
        while(t--){
            if(i<1) break;
            sp-=f[i];
            i--;
        }
        if(s<sp) break;  
        s=min(sp,s);
    }

    cout<<s<<endl;

    return 0;
}