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
int a[N];


int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        vector<int> l0,l1,l2;
        for(int i=1;i<=n;i++){
            if(a[i]==0) l0.push_back(i);
            else if(a[i]==1) l1.push_back(i);
            else if(a[i]==2) l2.push_back(i);
        }
        vector<pair<int,int>> res;

        

        for(int i=1;i<=n;i++){
            if(a[i]==0) l0.push_back(i);
            else if(a[i]==1) l1.push_back(i);
            else if(a[i]==2) l2.push_back(i);
        }

        cout<<res.size()<<endl;
        for(auto i:res){
            printf("%d %d\n",i.first,i.second);
        }

    }

    return 0;
}