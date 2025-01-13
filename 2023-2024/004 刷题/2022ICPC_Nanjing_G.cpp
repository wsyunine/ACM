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
#define N 1000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,a[N],num[N];
vector<int> s;

int gcd(int a,int b){
    return b>0?gcd(b,a%b):a;
}

int main(){

    read(t);
    while(t--){
        int ans1=1,ans2=1,op;
        bool idea=1;
        s.clear();
        read(n);
        for(int i=1;i<=n;i++) read(a[i]),a[i]==0?s.push_back(i):void();

        int cnt1=0,cntn1=0,cmt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt1++;
            else cntn1++;
            while(cnt1<cntn1&&cmt<s.size()&&s[cmt]<=i) a[s[cmt++]]=1,cntn1--,cnt1++;
            if(cnt1<cntn1){cout<<-1<<endl,idea=0;break;}
        }
        if(!idea) continue;

        for(int i=1;i<=n;i++){
            if(a[i]==1) ans1++,ans2++;
            else ans2--;
        }
        
        if(!idea) continue;
        int g=gcd(ans1,ans2);
        cout<<ans1/g<<" "<<ans2/g<<endl;
    }

    return 0;
}