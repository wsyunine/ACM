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
string s,s1,s2;
int ss[100000];

int main(){

    read(t);
    while(t--){
        cin>>s;s1.clear(),s2.clear();
        ss['R']=0,ss['G']=0,ss['B']=0;
        for(int i=0;i<8;i++){
            ss[s[i]]++;
            if(i%2==0) s1.push_back(s[i]);
        }
        for(int i=0;i<4;i++) if(i%2==0) s2.push_back(s1[i]);

        if(s2[0]==s2[1]) cout<<s2[0]<<endl;
        else if(ss[s2[0]]>ss[s2[1]]) cout<<s2[0]<<endl;
        else if(ss[s2[0]]<ss[s2[1]]) cout<<s2[1]<<endl;
        else cout<<"N"<<endl;
    }

    return 0;
}