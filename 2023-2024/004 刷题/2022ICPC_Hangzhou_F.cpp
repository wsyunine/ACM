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
map<string,bool> s;
string op;

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        int m,cnt=0;
        read(m);
        for(int j=1;j<=m;j++){
            cin>>op;
            int len=op.size(),idea=0;
            for(int k=0;k<len-2;k++){
                if(op[k]=='b'&&op[k+1]=='i'&&op[k+2]=='e'){idea=1;break;}
            }
            if(idea&&s.find(op)==s.end()) cout<<op<<endl,s[op]=1,cnt++; 
        }
        if(cnt==0) cout<<"Time to play Genshin Impact, Teacher Rice!"<<endl;
    }

    return 0;
}