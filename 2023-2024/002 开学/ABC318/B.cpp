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

int main(){

    int n,cnt=0;
    cin>>n;
    int mapp[110][110];
    vector<int> a(n+1),b(n+1),c(n+1),d(n+1);
    memset(mapp,0,sizeof(mapp));

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        for(int j=min(a[i],b[i])+1;j<=max(b[i],a[i]);j++){
            for(int k=min(c[i],d[i])+1;k<=max(c[i],d[i]);k++){
                mapp[j][k]=1;
            }
        }
    }

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(mapp[i][j]) cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}