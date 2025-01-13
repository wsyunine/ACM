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
            if(a[i]==1) l1.push_back(i);
            else if(a[i]==2) l2.push_back(i);
        }
        vector<pair<int,int>> res;

        reverse(l1.begin(),l1.end());
        l2.push_back(n+1);
        int lp=0,l2p=l2[lp];
        for(auto i:l1){
            if(i<l2p) break;
            res.push_back({l2p,i});
            a[l2p]=1;
            a[i]=2;
            lp++;
            l2p=l2[lp];
        }

        l1.clear();
        l2.clear();
        for(int i=1;i<=n;i++){
            if(a[i]==0) l0.push_back(i);
            else if(a[i]==1) l1.push_back(i);
            else if(a[i]==2) l2.push_back(i);
        }

        l1.push_back(n+1);
        l2.push_back(n+1);

        reverse(l0.begin(),l0.end());
        int lp1=0,l1p=l1[lp1],lp2=0;
        l2p=l2[lp2];
        for(auto i:l0){
            if(i<l1p) break;
            else if(i<l2p){
                res.push_back({l1p,i});
                lp1++;
                l1p=l1[lp1];
            }else{
                res.push_back({l1p,i});
                lp1++;
                l1p=l1[lp1];
                res.push_back({l2p,i});
                lp2++;
                l2p=l2[lp2];
            }
        }

        cout<<res.size()<<endl;
        for(auto i:res){
            printf("%d %d\n",i.first,i.second);
        }

    }

    return 0;
}