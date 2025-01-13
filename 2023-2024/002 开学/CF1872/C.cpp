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

    int t;
    read(t);
    while(t--){
        int l,r;
        read(l),read(r);
        if(r<4){
            cout<<-1<<endl;
            continue;
        }

        if(l<4){
            cout<<2<<" "<<2<<endl;
            continue;
        } 

        if(l%2==0){
            cout<<2<<" "<<l-2<<endl;
        }else{
            if(l==r){

                bool idea=0;

                for(int i=2;i*i<=l;i++){
                    if(l%i==0){
                        cout<<i<<" "<<l-i<<endl;
                        idea=1;
                        break;
                    }
                }

                if(idea==0) cout<<-1<<endl;

            }else{
                cout<<2<<" "<<l-1<<endl;
            }
        }
    }

    return 0;
}