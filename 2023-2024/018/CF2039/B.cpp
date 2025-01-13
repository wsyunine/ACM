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
string s;

int main(){

    read(t);
    while(t--){
        cin>>s;
        if(s.length()==1){
            cout<<-1<<endl;
            continue;
        }
        if(s.length()==2){
            if(s[0]==s[1]){
                cout<<s<<endl;
            }else cout<<-1<<endl;
            continue;
        }
        int idea=0;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                cout<<s[i-1]<<s[i]<<endl;
                idea=1;
                break;
            }
        }
        if(idea) continue;
        for(int i=1;i<s.length()-1;i++){
            if(s[i-1]!=s[i]&&s[i-1]!=s[i+1]&&s[i]!=s[i+1]){
                cout<<s[i-1]<<s[i]<<s[i+1]<<endl;
                idea=1;
                break;
            }
        }
        if(idea) continue;
        cout<<-1<<endl;
    }

    return 0;
}