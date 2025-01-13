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

int main(){

    int i;
    for(i=1;;i++){
        cout<<"The result of No. "<<i<<" Case is: "<<endl;
        system("./Erand");
        system("./Esample");
        system("./E");
        if(system("diff std.out test.out")){
            cout<<"Wrong Answer\n";
            return 0;
        }else cout<<"Accepted\n";
    }

    return 0;
}