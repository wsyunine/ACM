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
vector<int> res;
int w[N];

int main(){

    read(t);
    while(t--){
        read(n);
        res.clear();
        int l=1,tmp,r;
        int idea=1,ok=1;
        printf("? 1 %d\n",n);
        fflush(stdout);
        read(tmp);
        if(tmp==0){
            printf("! IMPOSSIBLE\n");
            fflush(stdout);
            continue;
        }

        int sum0=0;
        for(int r=2;r<=n;r++){
            printf("? 1 %d\n",r);
            fflush(stdout);
            read(w[r]);
            if(idea&&w[r]){
                idea=0;
                if(r-1-w[r]<0){ok=0;break;}
                for(int i=1;i<=r-1-w[r];i++) res.push_back(1);
                for(int i=1;i<=w[r];i++) res.push_back(0);
                res.push_back(1);
                sum0=w[r];
                continue;
            }
            if(!idea&&w[r]==w[r-1]) res.push_back(0),sum0++;
            if(!idea&&w[r]!=w[r-1]){
                if(w[r-1]+sum0!=w[r]){ok=0;break;}
                res.push_back(1);
            }
        }

        if(ok){
            printf("! ");
            for(auto i:res) printf("%d",i);
            cout<<endl;
            fflush(stdout);
        }else{
            printf("! IMPOSSIBLE\n");
            fflush(stdout);
        }
    }

    return 0;
}