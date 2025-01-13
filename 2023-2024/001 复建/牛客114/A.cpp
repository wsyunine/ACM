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
using namespace std;
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}


int main(){

    int n;
    bool is=0;
    cin>>n;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0) is=1;
    }

    if(is==0) cout<<-1<<endl;
    if(is==0) return 0;

    sort(s.begin()+1,s.end());
    for(int i=n;i>=1;i--) cout<<s[i];
    cout<<endl;

    return 0;
}