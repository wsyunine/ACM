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
int t;
int a[N];
int mapp[N],pos=0;
vector<pair<int,int>> ans;

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=0;i<=n;i++) mapp[i]=0;
        for(int i=1;i<=n;i++) read(a[i]),mapp[a[i]]=1;

        for(int i=0;i<=n;i++) if(!mapp[i]){pos=i;break;}

        ans.clear();
        unordered_map<int,int> op;
        int sum=0;
        for(int i=1,j=1;i<=n;i++){
            if(a[i]<pos){
                if(!op[a[i]]) op[a[i]]=1,sum++;
            }
            if(sum==pos){
                sum=0;
                ans.push_back(make_pair(j,i));
                j=i+1;
                op.clear();
            }
        }

        ans[ans.size()-1].second=n;

        if(ans.size()==1){
            cout<<-1<<endl;
        }else{
            cout<<ans.size()<<endl;
            for(auto i:ans){
                cout<<i.first<<" "<<i.second<<endl;
            }
        }
    }

    return 0;
}