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

    read(t);
    while(t--){
        read(n);

        if(n==2){
            cout<<"! 0 1"<<endl;
            continue;
        }

        int op=1;
        while(op-1<n) op*=2;
        op--;
        
        int pos=0;
        for(int i=1;i<n;i++){
            cout<<"? "<<pos<<" "<<pos<<" "<<i<<" "<<i<<endl;
            fflush(stdout);
            char s;
            cin>>s;
            if(s=='<'){
                pos=i;
            }
        }

        int k=0;
        vector<int> up;
        for(int i=0;i<n;i++){
            if(i==pos) continue;
            cout<<"? "<<k<<" "<<pos<<" "<<i<<" "<<pos<<endl;
            fflush(stdout);
            char s;
            cin>>s;
            if(s=='='){
                up.push_back(i);
            }else if(s=='<'){
                up.clear();
                up.push_back(i);
                k=i;
            }
        }

        int ans=up[0];
        for(auto i:up){
            cout<<"? "<<i<<" "<<i<<" "<<ans<<" "<<ans<<endl;
            fflush(stdout);
            char s;
            cin>>s;
            if(s=='=') continue;
            else if(s=='<'){
                ans=i;
            }
        }

        cout<<"! "<<ans<<" "<<pos<<endl;
    }

    return 0;
}