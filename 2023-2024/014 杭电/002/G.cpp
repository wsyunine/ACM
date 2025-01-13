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
string s;

int main(){

    read(t);
    while(t--){
        cin>>s;
        string op;
        int pos=0;
        for(;pos<s.length();pos++){
            if(s[pos]==':') break;
            op.push_back(s[pos]);
        }
        cout<<op<<endl;
        op.clear();
        pos++;pos++;pos++;
        for(;pos<s.length();pos++){
            if(s[pos]=='/') break;
            op.push_back(s[pos]);
        }
        cout<<op<<endl;
        op.clear();
        pos++;
        while(pos<s.length()){
            int id=0;
            for(;pos<s.length();pos++){
                if(s[pos]=='/') break;
                if(s[pos]=='=') id=1;
                op.push_back(s[pos]);
            }
            if(id) cout<<op<<endl;
            op.clear();
            pos++;
        }
    }

    return 0;
}