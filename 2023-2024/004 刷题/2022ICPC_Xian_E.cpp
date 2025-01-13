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
int l,r;
int cnt;
int mapp[2][40];

signed main(){

    read(t);
    while(t--){
        read(l),read(r);
        cnt=0;int ans=0;
        int idea=0;

        while(l>0||r>0){
            cnt++;
            mapp[0][cnt]=l%3,mapp[1][cnt]=r%3;
            l/=3,r/=3;
        }

        if(cnt==1){
            cout<<mapp[1][1]+1<<endl;
            continue;
        }

        if(mapp[0][cnt]!=mapp[1][cnt]) idea=1;

        int sum=mapp[1][cnt]+1;
        for(int i=cnt-1;i>=1;i--){
            if(idea==1&&mapp[1][i]!=0&&i!=1){
                sum+=mapp[1][i];sum+=(i-1)*3;
                ans=max(ans,sum);
                sum-=mapp[1][i];sum-=(i-1)*3;
            }
            if(mapp[0][i]==mapp[1][i]) sum+=mapp[1][i]+1;
            else if(i!=1&&idea==0){
                sum+=mapp[1][i];sum+=(i-1)*3;
                ans=max(ans,sum);
                sum-=mapp[1][i];sum-=(i-1)*3;
                sum+=mapp[1][i]+1;
                idea=1;
            }else{sum+=mapp[1][i]+1;}
        }

        ans=max(ans,sum);

        if(mapp[0][cnt]==mapp[1][cnt]);
        else if(mapp[1][cnt]==2) ans=max(ans,3*(cnt-1)+2);
        else if(mapp[1][cnt]==1) ans=max(ans,3*(cnt-1));

        cout<<ans<<endl;
    }

    return 0;
}