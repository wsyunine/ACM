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

    int tmp=0;
    for(int i=1;i<10000;i++){
        system("./data");
        system("./test1");
        system("./test2");

        if(system("diff test1.out test2.out")){
            printf("wrong in --> %d \n",i);
            break;
        }
        printf("process %d is correct\n",i);
    }

    return 0;
}