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
char a[N][31];
float b[N];

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        gets(a[i]);
        scanf("%f",&b[i]);
    }

    int j=0;
    float t=b[0];
    for(int i=1;i<n;i++){
        if(t<b[i]){
            t=b[i];
            j=i;
        }
    }

    printf("%.2f,%s\n",t,a[j]);

    return 0;
}