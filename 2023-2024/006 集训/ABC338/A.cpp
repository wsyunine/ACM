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

string s;

int main(){

    cin>>s;
    bool idea=1;
    for(int i=0;i<s.length();i++){
        if(i!=0&&s[i]>='A'&&s[i]<='Z') idea=0;
        else if(i==0&&s[i]>='a'&&s[i]<='z') idea=0;
    }
    if(idea) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}