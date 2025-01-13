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
int t;
int m;

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        vector<vector<int>> num(n+1);
        vector<int> lst(m+1,0);
        for(int i=1;i<=n;i++){
            int opt,op;
            read(opt);
            num[i].push_back(opt);
            for(int j=1;j<=opt;j++){
                read(op);
                num[i].push_back(op);
                lst[op]=i;
            }
        }

        //for(int i=1;i<=m;i++) cout<<lst[i]<<" ";


        int idea=0,tmp=-1;
        //vector<bool> vis(m+1);
        for(int i=1;i<n;i++){
            int id=1;
            for(int j=1;j<=num[i][0];j++){
                if(lst[num[i][j]]==i+1) id=0;
            }
            if(id) idea=1,tmp=i+1;
        }

        if(!idea){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(int i=1;i<=n;i++){
            if(i==(tmp-1+n)%n) printf("%d ",tmp);
            else if(i==tmp) printf("%d ",tmp-1);
            else printf("%d ",i);
        }
        printf("\n");
    }

    return 0;
}