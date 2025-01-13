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
#define N 800010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

long long n,m;
int a[N];
long long ans=0;
int idea=1,top;
string s;
long long t[N];

void add(int x,int k){
    for(;x<=n;x+=x&-x) t[x]+=k;
}

int query(int x){
    int res=0;
    for(;x;x-=x&-x) res+=t[x];
    return res;
}

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++) read(a[i]);
    cin>>s;

    for(int i=n;i>=1;i--){
        ans+=query(a[i]);
        add(a[i],1);
    }

    cout<<ans<<endl;
    ans%=10;
    top=1;

    for(int i=0;i<m;i++){
        if(s[i]=='S'){
            if(idea==1){
                (ans+=(n-a[top]))%=10;
                ans=((ans-(a[top]-1))%10+10)%10;
                top==n?top=1:top=top+1;
            }else{
                (ans+=(n-a[top]))%=10;
                ans=((ans-(a[top]-1))%10+10)%10;
                top==1?top=n:top=top-1;
            }
        }else if(s[i]=='R'){
            if(idea==1) top==1?top=n:top=top-1;
            else top==n?top=1:top=top+1;
            idea=-idea;
            ans=((((n-1)*n/2)%10-ans)%10+10)%10;
        }
        cout<<(ans%10+10)%10;
    }
    cout<<endl;
    
    return 0;
}