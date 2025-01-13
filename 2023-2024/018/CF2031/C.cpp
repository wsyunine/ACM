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

int main(){

    read(t);
    while(t--){
        read(n);
        if(n%2){
            int x=sqrt(n);
            if(n==25){cout<<-1<<endl;continue;}
            if(x==1||x==0){cout<<-1<<endl;continue;} 
            if(x<5){cout<<-1<<endl;continue;}
            printf("1 ");
            int tmp=2;
            for(int i=2;i<=3*3;i+=2){
                printf("%d %d ",tmp,tmp);
                tmp++;
            }
            printf("1 ");
            for(int i=11;i<23;i+=2){
                printf("%d %d ",tmp,tmp);
                tmp++;
            }
            printf("%d %d %d %d %d ",tmp,tmp+1,tmp+1,1,tmp);
            tmp+=2;
            for(int i=28;i<=n;i+=2){
                printf("%d %d ",tmp,tmp);
                tmp++;
            }
            cout<<endl;
        }else{
            for(int i=1;i<=n;i++){
                printf("%d ",(i+1)/2);
            }
            cout<<endl;
        }
    }

    return 0;
}