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

    int n;
    cin>>n;
    vector<int> s(n+1);

    for(int i=1;i<=n;i++) cin>>s[i];

    sort(s.begin()+1,s.end());

    int st=s[1];
    for(int i=2;i<=n;i++){
        if(st+i-1!=s[i]){
            cout<<st+i-1<<endl;
            return 0;
        }
    }

    return 0;
}