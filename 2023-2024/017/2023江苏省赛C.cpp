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

int n;
int t;
int tmp=0,pos;

bool check(int x){
    int op;
    cout<<"? "<<(pos+x-1ll)%n+1ll<<endl;
    fflush(stdout);
    cin>>op;

    if(op==tmp) return 1;
    else return 0;
}

signed main(){

    read(t);
    while(t--){
        read(n);
        printf("? 1\n");
        fflush(stdout);
        read(tmp);

        int tmp1,tmp2;
        pos=1;
        printf("? %lld\n",n);
        fflush(stdout);
        read(tmp1);
        printf("? %lld\n",2ll);
        fflush(stdout);
        read(tmp2);

        if(tmp1>tmp&&tmp2<tmp){
            printf("? %lld\n",1ll+n/4ll);
            fflush(stdout);
            read(tmp1);
            printf("? %lld\n",1ll+n/4ll+1ll);
            fflush(stdout);
            read(tmp2);

            if(tmp1<=tmp&&tmp1<=tmp2) pos=1ll+n/4ll,tmp=tmp1;
            else if(tmp2<=tmp&&tmp2<=tmp1) pos=1ll+n/4ll+1ll,tmp=tmp2;
        }else if(tmp1<tmp&&tmp2>tmp){
            printf("? %lld\n",1ll+n-n/4ll);
            fflush(stdout);
            read(tmp1);
            printf("? %lld\n",1ll+n-n/4ll-1ll);
            fflush(stdout);
            read(tmp2);

            if(tmp1<=tmp&&tmp1<=tmp2) pos=1ll+n-n/4ll,tmp=tmp1;
            else if(tmp2<=tmp&&tmp2<=tmp1) pos=1ll+n-n/4ll-1ll,tmp=tmp2;
        }else{
            printf("? %lld\n",n/2ll+1ll);
            fflush(stdout);
            read(tmp1);
            printf("? %lld\n",n/2ll+2ll);
            fflush(stdout);
            read(tmp2);

            if(tmp1<=tmp&&tmp1<=tmp2) pos=n/2ll+1ll,tmp=tmp1;
            else if(tmp2<=tmp&&tmp2<=tmp1) pos=n/2ll+2ll,tmp=tmp2;
        }

        cout<<pos<<" "<<tmp<<endl;

        int l=0,r=n/2ll;
        while(l<r){
            int mid=(l+r+1ll)>>1ll;
            if(check(mid)) l=mid;
            else r=mid-1;
        }

        int res=(pos+l-1ll)%n+1ll;
        printf("! %lld %lld\n",res,(res+n-tmp-1ll)%n+1ll);
        fflush(stdout);
    }

    return 0;
}