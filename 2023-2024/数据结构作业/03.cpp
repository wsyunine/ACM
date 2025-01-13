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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
pair<double,double> dot[N];
vector<pair<double,int>> slope[N];
int res1,res2,res3;

int main(){

    cin>>n;
    for(int i=1;i<=n;i++) cin>>dot[i].first>>dot[i].second;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            slope[i].push_back({(dot[i].second-dot[j].second)/(dot[i].first-dot[j].first),j});
        }
        sort(slope[i].begin(),slope[i].end());
    }
    for(int i=1;i<=n;i++){
        double op=slope[i][0].first;
        int cnt=1;
        for(int j=1;j<slope[i].size();j++){
            if(slope[i][j].first==op) cnt++;
            else cnt=1,op=slope[i][j].first;
            if(cnt==2){
                res1=i;
                res2=slope[i][j].second;
                res3=slope[i][j-1].second;
            }
        }
    }
    cout<<res1<<" "<<res2<<" "<<res3<<endl;
    

    return 0;
}