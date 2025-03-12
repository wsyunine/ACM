#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
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
int sum[33];

void solve() {
    int op=0,ans;
    for(int i=0;i<30;i++) sum[i]=0;
    for(int i=1,j=2;i<30;i+=2,j<<=2ll){
        op+=j;
    }
    cout<<op<<endl;
    cin>>ans;

    // for(int i=0;i<30;i++){
    //     cout<<((ans>>i)&1)<<" ";
    // }
    // cout<<endl;

    for(int i=0;i<30;i++){
        if(i==0){
            int p1=(ans>>i)&1;
            i++;
            int p2=(ans>>i)&1;

            if(p1==0&&p2==1) sum[i-1]=2;
            if(p1==0&&p2==0) sum[i-1]=0;
            if(p1==1) sum[i-1]=1;
        }else{
            int p1=(ans>>i)&1;
            i++;
            int p2=(ans>>i)&1;

            if(p1==1&&p2==1) sum[i-1]=2;
            if(p1==0&&p2==1) sum[i-1]=1;
            if(p1==1&&p2==0) sum[i-1]=0;
        }
    }

    op=0;
    for(int i=0,j=1;i<30;i+=2,j<<=2ll){
        op+=j;
    }
    cout<<op<<endl;
    cin>>ans;
    for(int i=1;i<30;i++){
        int p1=(ans>>i)&1;
        i++;
        int p2=(ans>>i)&1;

        if(p1==1&&p2==1) sum[i-1]=2;
        if(p1==0&&p2==1) sum[i-1]=1;
        if(p1==1&&p2==0) sum[i-1]=0;
    }

    cout<<"!"<<endl;

    cin>>ans;

    int res=0;
    for(int i=0,j=1;i<30;i++,j<<=1ll){
        if((ans>>i)&1ll){
            res+=2ll*j;
        }else{
            res+=sum[i]*j;
        }
    }
    
    cout<<res<<endl;
}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}