#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n,m,q;
int a[N];
int l,r;
int kg=0,kg1=0;
int r1,l2;

void solve() {
    kg=0;kg1=0;
    read(n),read(m),read(q);
    // for(int i=1;i<=n;i++) read(a[i]);
    l=m,r=m;

    for(int i=1;i<=q;i++){
        int opt;
        read(opt);

        if(kg){
            if(opt>r1) if(r1<n) r1++;
            if(opt<l2) if(l2>1) l2--;
        }

        if(opt<l){
            if(l>1) l--;
            if(i==1) kg1=1;  
        }else if(opt>r){
            if(r<n) r++;
            if(i==1) kg1=1;
        }else if(kg==0&&l<=opt&&r>=opt){
            kg=1;
            r1=1;
            l2=n;
        }

        int res=0;

        if(kg1){
            res=r-l+1;
        }

        if(kg){
            if(kg1&&r1>=l) r1=l-1;
            if(kg1&&l2<=r) l2=r+1;

            if(l2<=r1) l2=r1+1; 

            res+=r1+(n-l2+1);
        }

        cout<<res<<" ";
    }
    cout<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}