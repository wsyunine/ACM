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
    while(n--){
        int l,ansl;
        cin>>l;
        ansl=l;
        vector<int> s(l+1);
        s[0]=-1;
        for(int i=1;i<=l;i++) cin>>s[i],s[i]>=s[i-1]?:ansl++;

        cout<<ansl<<endl;
        for(int i=1;i<=l;i++){
            if(s[i]>=s[i-1]){
                cout<<s[i]<<" ";
            }else{
                cout<<s[i]<<" "<<s[i]<<" ";
            }
        }
        cout<<endl;

    }

    return 0;
}