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

int n,q;
int sx[N],sy[N],cnt=0;

int main(){

    read(n),read(q);

    for(int i=1;i<=q;i++){
        int opt,s;
        char k;
        read(opt);
        if(opt==1){
            cin>>k;
            cnt++;
            if(k=='R') sx[cnt]=sx[cnt-1]+1,sy[cnt]=sy[cnt-1];
            else if(k=='L') sx[cnt]=sx[cnt-1]-1,sy[cnt]=sy[cnt-1];
            else if(k=='U') sx[cnt]=sx[cnt-1],sy[cnt]=sy[cnt-1]+1;
            else if(k=='D') sx[cnt]=sx[cnt-1],sy[cnt]=sy[cnt-1]-1;
        }else{
            read(s);
            if(cnt-s+1>=0){
                cout<<sx[cnt-s+1]+1<<" "<<sy[cnt-s+1]<<endl;
            }else{
                cout<<s-cnt<<" 0"<<endl;
            }
        }
    }

    return 0;
}