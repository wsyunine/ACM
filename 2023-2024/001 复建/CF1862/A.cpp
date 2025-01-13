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
    cin>>n;
    while(n--){
        int x,y;
        char u[5]={'v','i','k','a'};
        int po=0;
        string a[21];
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            cin>>a[i];
        }
        for(int i=0;i<y;i++){
            for(int j=1;j<=x;j++){
                if(a[j][i]==u[po]){
                    po++;
                    break;
                }
            }
        }
        if(y<4){cout<<"NO"<<endl;continue;}
        if(po==4) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}