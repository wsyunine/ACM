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
#define N 5000010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int d[N],fa[N];

int main(){

    read(n);read(m);

    if(m==1){
        for(int i=1;i<n;i++){
            read(fa[i]);
            d[i]++;
            d[fa[i]]++;
        }

        int p;
        for(int i=1;i<=n;i++) if(d[i]==1){p=i;break;}

        vector<int> prufer;
        int l=p;
        while(prufer.size()<n-2){
            int f=fa[l];
            prufer.push_back(f);
            d[f]--;
            if(d[f]==1&&f<p) l=f;
            else{
                p++;
                while(d[p]!=1) p++;
                l=p;
            }
        }

        ll ans=0;
        for(int i=0;i<n-2;i++) ans=ans^((ll)(i+1)*(ll)prufer[i]);
        cout<<ans<<endl;
    }else{
        vector<int> prufer(n);
        for(int i=1;i<=n-2;i++) read(prufer[i]),d[prufer[i]]++;
        for(int i=1;i<=n;i++) d[i]++;

        int p;
        for(int i=1;i<=n;i++) if(d[i]==1){p=i;break;}

        int l=p;
        for(int i=1;i<=n-2;i++){
            int f;
            f=fa[l]=prufer[i];
            d[f]--;
            if(d[f]==1&&f<p) l=f;
            else{
                p++;
                while(d[p]!=1) p++;
                l=p;
            }
        }
        fa[l]=n;

        ll ans=0;
        for(int i=1;i<=n;i++) ans=ans^((ll)i*(ll)fa[i]);
        cout<<ans<<endl;
    }

    return 0;
}
/*
7
2 0 2 2 3 3 2
*/