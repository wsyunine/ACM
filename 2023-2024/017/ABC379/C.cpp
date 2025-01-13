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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int sum=0;
pair<int,int> s[N];

signed main(){

    read(n),read(m);

    for(int i=1;i<=m;i++){
        read(s[i].first);
    }
    for(int i=1;i<=m;i++){
        read(s[i].second);sum+=s[i].second;
    }
    sort(s+1,s+1+m);

    if(sum!=n){
        cout<<-1<<endl;
    }else if(s[1].first!=1){
        cout<<-1<<endl;
    }else{
        int idea=1,tmp=s[1].second;
        int res=0;
        s[m+1].first=n+1;
        for(int i=2;i<=m+1;i++){
            if(s[i].first-s[i-1].first>tmp){
                idea=0;
                break;
            }else{
                res+=(s[i].first-s[i-1].first-1ll)*(s[i].first-s[i-1].first)/2ll+(tmp-(s[i].first-s[i-1].first))*(s[i].first-s[i-1].first);
                tmp=tmp+s[i].second-(s[i].first-s[i-1].first);
            }
        }
        if(idea) cout<<res<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}