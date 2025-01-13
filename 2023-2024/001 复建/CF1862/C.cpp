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

    int P;
    cin>>P;
    while(P--){
        int n;
        bool ans=1;
        cin>>n;
        vector<int> s(n+1),s1(n+1);
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        if(s[1]!=n){
            cout<<"NO"<<endl;
            continue;
        }

        int po=1,nu=0;
        for(int i=n;i>=1;i--){
            while(s[po+1]==i) po++;
            s1[i]=po;
        }

        for(int i=1;i<=n;i++){
            if(s1[i]!=s[i]) ans=0;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}