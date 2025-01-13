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
string s;
int w[N],l[N];
vector<int> pos;

int main(){

    read(n);
    cin>>s;

    for(int i=1;i<n-1;i++){
        if(s[i]>s[i-1]&&s[i]>s[i+1]) w[i]=1;
        if(s[i]<s[i-1]&&s[i]<s[i-1]) l[i]=1;
    }

    for(int i=1;i<n-1;i++){
        if(l[i]==1&&w[i-1]==1&&w[i+1]==1) pos.push_back(i);
    }

    cout<<pos.size()<<endl;
    for(auto i:pos){
        cout<<i+1<<" ";
    }
    cout<<endl;

    return 0;
}