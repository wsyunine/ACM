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

int t;
int n;

int main(){

    read(t);
    while(t--){

        read(n);

        if(n<5){
            cout<<-1<<endl;
        }else if(n==5){
            printf("3 1 5 4 2\n");
        }else if(n==6){
            printf("2 4 6 3 1 5\n");
        }else if(n==7){
            printf("2 4 6 3 1 5 7\n");
        }else{
            for(int i=2;i<=n;i+=2){
                if(i!=8) printf("%d ",i);
            }
            printf("8 1 ");
            for(int i=3;i<=n;i+=2){
                printf("%d ",i);
            }
            cout<<endl;
        }
        
    }

    return 0;
}