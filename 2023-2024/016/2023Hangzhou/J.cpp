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
int t;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    read(t);
    while(t--){
        read(n);
        int op1=0,op2=0,op3,op4;
        for(int i=1;i<=n/2;i++){
            int op;
            cout<<"? "<<2*i-1<<" "<<2*i<<endl;
            fflush(stdout);
            cin>>op;
            if(op){
                op1=2*i-1;
                op2=op1+1;
                op3=(op1+2)>n?1:op1+2;
                op4=(op1+3)>n?2:op1+3;
                break;
            }
        }
        if((n&1)&&!op1){
            int op;
            cout<<"? "<<n<<" "<<1<<endl;
            fflush(stdout);
            cin>>op;
            if(op){
                op1=n;
                op2=1;
                op3=2;
                op4=3;
            }
        }
        if(!op1&&!op2){
            cout<<"! 1"<<endl;
            fflush(stdout);
            continue;
        }
        int op;
        cout<<"? "<<op1<<" "<<op3<<endl;
        fflush(stdout);
        cin>>op;
        if(op){
            cout<<"? "<<op1<<" "<<op4<<endl;
            fflush(stdout);
            cin>>op;
            if(op){
                cout<<"! 2"<<endl;
                fflush(stdout);
            }else{
                cout<<"! 1"<<endl;
                fflush(stdout);
            }
            continue;
        }
        cout<<"? "<<op2<<" "<<op3<<endl;
        fflush(stdout);
        cin>>op;
        if(op){
            cout<<"? "<<op2<<" "<<op4<<endl;
            fflush(stdout);
            cin>>op;
            if(op){
                cout<<"! 2"<<endl;
                fflush(stdout);
            }else{
                cout<<"! 1"<<endl;
                fflush(stdout);
            }
            continue;
        }
        cout<<"! 1"<<endl;
    }

    return 0;
}