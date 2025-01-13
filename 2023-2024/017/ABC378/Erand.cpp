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

int a[10000];

int main(){

    freopen("Edata.in","w",stdout);

    srand(time(0));

    int n=rand()%20+1;
    int m=rand()%20+1;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        a[i]=rand()%20+1;
        cout<<a[i]<<" "; 
    }
    cout<<endl;
    fclose(stdout);

    return 0;
}