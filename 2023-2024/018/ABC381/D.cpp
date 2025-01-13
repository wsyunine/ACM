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

int n;
int a[N],d[N];

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    vector<int> b;
    b.push_back(0);
    vector<int> s;
    s.push_back(0);

    int op=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            b.push_back(a[i-1]);
            s.push_back(op);
            op=1;
        }else{
            op++;
        }
    }
    b.push_back(a[n]);
    s.push_back(op);

    int m=b.size(),ans=0,l=1,tmp=0;
    for(int i=1;i<m;i++){
        if(s[i]==1){
            tmp=0;
            l=i+1;
        }else if(s[i]==2){
            if(!d[b[i]]) tmp+=2;
            else if(d[b[i]]>=l){
                l=d[b[i]]+1;
                tmp=(i-l+1)*2;
            }else{
                tmp+=2;
            }
            d[b[i]]=i;
        }else{
            if(!d[b[i]]) tmp+=2;
            else if(d[b[i]]>=l){
                l=d[b[i]]+1;
                tmp=(i-l+1)*2;
            }else{
                tmp+=2;
            }
            ans=max(ans,tmp);
            d[b[i]]=i;
            l=i;tmp=2;
        }
        //cout<<tmp<<endl;
        ans=max(ans,tmp);
    }

    cout<<ans<<endl;

    return 0;
}