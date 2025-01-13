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

int n,m;
struct node{
    string name;
    int sum,kk;
}a[N],b[N];
map<string,int> s;

bool cmp(node a,node b){
    return (a.sum==b.sum)?(a.kk<b.kk):(a.sum>b.sum);
}

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        cin>>a[i].name;
        read(a[i].sum);
        read(a[i].kk);
        s[a[i].name]++;
    }
    read(m);
    for(int i=1;i<=m;i++){
        cin>>b[i].name;
        read(b[i].sum);
        read(b[i].kk); 
        s[b[i].name]++;
    }

    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);

    int op1=0,op2=0;
    for(int i=1;i<=n;i++){
        if(s[a[i].name]==1) op1++;
        if(a[i].name=="lzr010506"){
            op1++;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(s[b[i].name]==1) op2++;
        if(b[i].name=="lzr010506"){
            op2++;
            break;
        }
    }

    cout<<min(op1,op2)<<endl;

    return 0;
}
/*

5
pku 10 1513
thu 8 1195
lzr010506 8 1234
MIT 9 816
ntu 8 1325
4
mipt 9 1143
ntu 7 962
lzr010506 9 1523
pku 9 1068
*/