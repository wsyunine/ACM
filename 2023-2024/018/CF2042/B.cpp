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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
int a[N];

signed main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);

        sort(a+1,a+1+n);
        vector<int> s;
        int tmp=1;
        int s1=0,res=0,s2=0;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]) tmp++;
            else{
                s.push_back(tmp);
                if(tmp==1) s1++;
                else s2++;
                tmp=1;
            }
        }
        if(tmp==1) s1++;
        else s2++;
        s.push_back(tmp);

        if(s1) res+=2*((s1-1)/2+1);
        res+=s2;
        cout<<res<<endl;

    }

    return 0;
}