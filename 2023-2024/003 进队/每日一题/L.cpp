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

int n;
pair<string,int> s[N];
int ans[N];

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        cin>>s[i].first;
        s[i].second=i;
    }

    sort(s+1,s+1+n);

    // for(int i=1;i<=n;i++) cout<<s[i].first<<" "<<s[i].second<<endl;

    for(int i=1;i<n;i++){
        int pos=0;
        int len=min(s[i].first.size(),s[i-1].first.size());
        for(int j=0;j<len;j++){
            if(s[i].first[j]!=s[i-1].first[j]) break;
            else ans[s[i].second]++;
        }
        len=min(s[i].first.size(),s[i+1].first.size());
        for(int j=0;j<len;j++){
            if(s[i].first[j]!=s[i+1].first[j]) break;
            else pos++;
        }
        ans[s[i].second]=max(ans[s[i].second],pos);
    }

    int len=min(s[n].first.size(),s[n-1].first.size());
    for(int j=0;j<len;j++){
        if(s[n].first[j]!=s[n-1].first[j]) break;
        else ans[s[n].second]++;
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;

    return 0;
}