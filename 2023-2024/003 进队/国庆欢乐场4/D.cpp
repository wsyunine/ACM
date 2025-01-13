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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;

signed main(){

    read(t);
    for(int tmp=1;tmp<=t;tmp++){
        int a,b,cnta1=0,cnta0=0,cntb1=0,cntb0=0,ans=0;
        vector<int> mapp[2][2];
        read(a),read(b);

        for(int i=0;i<=62;i++){
            if(a>>i&1){
                if(i&1) cnta1++,mapp[0][1].push_back(i);
                else cnta0++,mapp[0][0].push_back(i);
            }
            if(b>>i&1){
                if(i&1) cntb1++,mapp[1][1].push_back(i);
                else cntb0++,mapp[1][0].push_back(i);
            }
        }

        if(cnta1!=cntb1||cnta0!=cntb0){
            cout<<"Case "<<tmp<<": -1"<<endl;
            continue;
        }

        int len1=mapp[0][1].size(),len0=mapp[0][0].size();
        for(int i=0;i<len1;i++){
            ans+=abs(mapp[0][1][i]-mapp[1][1][i])/2;
        }
        for(int i=0;i<len0;i++){
            ans+=abs(mapp[0][0][i]-mapp[1][0][i])/2;
        }
        cout<<"Case "<<tmp<<": "<<ans<<endl;
    }

    return 0;
}