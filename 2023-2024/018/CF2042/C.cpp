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
string s;
int a[N],s1[N],s0[N],mx[N],mxp[N],k;
priority_queue<int> q;

int main(){

    read(t);
    while(t--){
        read(n);read(k);
        cin>>s;
        while(q.size()) q.pop();
        for(int i=1;i<=n;i++) s[i-1]=='1'?a[i]=1:a[i]=0;
        s1[0]=0,s0[0]=0;mx[0]=0;mxp[0]=0;
        for(int i=1;i<=n;i++){
            s1[i]=s1[i-1]+(a[i]==1);
            s0[i]=s0[i-1]+(a[i]==0);
        }
        mx[n]=s0[n]-s1[n],mxp[n]=n;
        for(int i=n-1;i>0;i--){
            if(s1[n]-s1[i]-s0[n]+s0[i]>0) q.push(s1[n]-s1[i]-s0[n]+s0[i]);
        }

        if(k==0){
            cout<<1<<endl;
            continue;
        }

        int res=1,sum=0;
        while(q.size()&&sum<k){
            res++;
            sum+=q.top();
            q.pop();
        }

        if(sum<k) cout<<-1<<endl;
        else cout<<res<<endl;
    }

    return 0;
}