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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
pair<int,int> s[N];

int main(){

    read(t);
    while(t--){
        read(n);
        if(n<6){
            for(int i=2;i<=n+1;i++) cout<<"1 "<<i<<endl;
            continue;
        }else if(n<9){
            cout<<"1 2\n1 3\n1 4\n1 5\n";
            for(int i=7;i<=n;i++) cout<<"1 "<<i-1<<endl;
            cout<<"2 3\n2 4\n";
            continue;
        }

        int cnt=0;
        s[++cnt]={1,n/3+1};
        s[++cnt]={1,n/3+2};
        s[++cnt]={1,n/3+3};
        s[++cnt]={1,2};
        s[++cnt]={2,n/3+1};
        s[++cnt]={2,n/3+2};
        s[++cnt]={1,3};
        s[++cnt]={2,3};
        s[++cnt]={3,n/3+1};
        for(int i=4;i<=n/3;i++){
            s[++cnt]={1,i};
            s[++cnt]={2,i};
            s[++cnt]={3,i};
        }
        if(n%3>=1) s[++cnt]={1,n/3+4};
        if(n%3>=2) s[++cnt]={1,n/3+5};
        sort(s+1,s+1+cnt);
        for(int i=1;i<=n;i++) cout<<s[i].first<<" "<<s[i].second<<endl;
    }

    return 0;
}