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
#define N 200010
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
int s[11][11][N];

int f[N];

int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}

void merge(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx!=yy) f[xx]=yy;
}

int main(){

    read(t);
    while(t--){
        read(n);
        read(m);
        int ans=0;
        for(int i=1;i<=10;i++){
            for(int j=0;j<i;j++){
                for(int k=0;k<=n;k++){
                    s[i][j][k]=0;
                }
            }
        }
        for(int i=1;i<=m;i++){
            int a,b,c;
            read(a),read(b),read(c);
            s[b][a%b][a/b+1]++;
            s[b][a%b][a/b+c+1]--;
        }

        for(int i=1;i<=n;i++) f[i]=i;

        for(int i=1;i<=10;i++){
            for(int j=0;j<i;j++){
                for(int k=1;k<=n;k++){
                    s[i][j][k]+=s[i][j][k-1];
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=10;j++){
                if(s[j][i%j][i/j]) merge(i,i-j);
            }
        }

        for(int i=1;i<=n;i++) if(find(i)==i) ans++;
        cout<<ans<<endl;
    }


    return 0;
}
