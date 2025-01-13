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

int t;

signed main(){

    read(t);
    for(int tmp=1;tmp<=t;tmp++){
        int n,cnt1=0,cnt2=0;
        read(n);
        vector<int> s(n+2);
        vector<int> oph;
        vector<int> opl;
        s[n+1]=0x3f3f3f3f;

        for(int i=1;i<=n;i++) read(s[i]),cnt1+=s[i];
        
        if(s[1]<s[2]) opl.push_back(1);
        
        for(int i=2;i<=n;i++){
            if(s[i]>s[i-1]&&s[i]>s[i+1]) oph.push_back(i);
            if(s[i]<s[i-1]&&s[i]<s[i+1]) opl.push_back(i);
        }

        if(opl[0]!=1){
            cnt2+=(opl[0]-1)*opl[0]/2;
        }

        int len=opl.size();
        for(int i=1,j=0;i<len;i++,j++){
            int a=oph[j]-opl[i-1]-1;
            int b=opl[i]-oph[j]-1;
            if(a<b) swap(a,b);
            a++;
            cnt2+=(1+b)*b/2;
            cnt2+=(1+a)*a/2;
        }

        if(opl[len-1]!=n){
            cnt2+=(n-opl[len-1]+1)*(n-opl[len-1])/2;
        }

        if((cnt1-cnt2)%2) cout<<"Case "<<tmp<<": "<<"Alice"<<endl;
        else cout<<"Case "<<tmp<<": "<<"Bob"<<endl;
    }

    return 0;
}