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

int t,n;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int mindiv(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return i;
    }
    return x;
}

signed main(){

    read(t);
    for(int tmp=1;tmp<=t;tmp++){
        read(n);
        bool idea=1;
        vector<int> a;
        for(int i=1,j;i<=n;i++) read(j),a.push_back(j),(j!=1?idea=0:1);

        if(idea){
            cout<<"Case "<<tmp<<": 1"<<endl;
            continue;
        }
        
        int gg=a[0];
        for(int i=1;i<n;i++) gg=gcd(gg,a[i]);
        if(gg>1){
            cout<<"Case "<<tmp<<": 0"<<endl;
            continue;
        }

        sort(a.begin(),a.end());

        int g=0;
        for(int i=0;i<n-1;i++){
            while(g==0&&i<n-2) g=a[i+1]-a[i],i++;
            while(a[i+1]-a[i]==0&&i<n-2) i++;
            g=gcd(g,a[i+1]-a[i]);
        }
        // cout<<g<<endl;
        if(g==1) cout<<"Case "<<tmp<<": -1"<<endl;
        if(g==0) cout<<"Case "<<tmp<<": 0"<<endl;
        if(g>1) g=mindiv(g),cout<<"Case "<<tmp<<": "<<g-(((a[0]-1)%g)+1)<<endl;
    }

    return 0;
}