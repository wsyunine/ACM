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
int m;
int a[2000010];
int num[5010],cnt=0;
int f[5010][5010];
int t[100010];

void add(int x,int y){
    for(;x<=90010;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
        if(!a[i]) num[++cnt]=i;
    }
    num[0]=0;
    //num[++cnt]=n+1;

    for(int i=2;i<=cnt;i++){
        for(int j=num[i-1]+1;j<num[i];j++){
            add(a[j]+5010,1);
        }
        for(int j=0;j<=i;j++){
            int res1=max(query(j-1+5010)-query(5010-(i-j)-1),0);
            int res2=max(query(j+5010)-query(5010-(i-j-1)-1),0);
            if(i-1>=j) f[i][j]=max(f[i-1][j]+res2,f[i][j]);
            if(j) f[i][j]=max(f[i][j],f[i-1][j-1]+res1);
            //cout<<f[i][j]<<" ";
        }
        //cout<<endl;
        for(int j=num[i-1]+1;j<num[i];j++){
            add(a[j]+5010,-1);
        }
    }

    int ress=0;
    for(int i=num[cnt]+1;i<=n;i++){
        add(a[i]+5010,1);
    }
    for(int i=0;i<=cnt;i++){
        ress=max(ress,f[cnt][i]+max(query(i+5010)-query(5010-(cnt-i)-1),0));
    }

    cout<<ress<<endl;

    return 0;
}