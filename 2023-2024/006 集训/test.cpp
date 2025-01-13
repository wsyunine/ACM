#include<iostream>
#include<vector>
using namespace std;
const int N=110;
const int M=1<<10;
vector<int> state;//
vector<int>head[M];
int n,m;
int g[N];
int f[2][M][M];
int cnt[M];
bool check(int x){
    //查一下x,看他是不是满足相隔两个
    for(int i=0;i<m;i++){
        if((x>>i&1)&&((x>>i+1&1)|(x>>i+2)&1))
        return false;
    }
    return true;
}
int count(int x){
    int res=0;
    for(int i=0;i<m;i++){
        if(x&1)res++;
        x>>=1;
    }
    cout<<res<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='H')g[i]+=1<<j;
        }
    }
   // cout<<g[1]<<" "<<g[2]<<" "<<g[3]<<" "<<g[4]<<" "<<g[5];
    for(int i=0;i<1<<m;i++){
        if(check(i))
        {state.push_back(i);
       cnt[i]=count(i);
    }
   }
   for(int i=1;i<=n+2;i++){
    for(int j=0;j<state.size();j++){
        for(int k=0;k<state.size();k++){
            for(int u=0;u<state.size();u++){
                int a=state[j],b=state[k],c=state[u];
                if((a&b==0)||(a&c==0)&(b&c==0))continue;
                if(a&g[i]&&b&g[i-1])
                f[i&1][a][b]=max(f[i&1][a][b],f[i-1&1][b][c]+cnt[a]);
            }
        }
    }
   }
   cout<<count(432);
  // cout<<f[n+2&1][0][0];

}