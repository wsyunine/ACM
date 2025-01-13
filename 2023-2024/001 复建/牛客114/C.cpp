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
#include<unordered_map>
using namespace std;
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.first<b.first;
}

int main(){

    int P;
    cin>>P;
    while(P--){
        int n,m;
        cin>>n>>m;
        vector<int> s(n+1);
        for(int i=1;i<=n;i++) cin>>s[i];
        unordered_map<int,int> mapp;
        int pos=s[1],sum=1;
        for(int i=2;i<=n;i++){
            if(s[i]==s[i-1]+1){
                sum++;
            }else{
                mapp[pos]=max(mapp[pos],sum);
                pos=s[i];sum=1;
            }
        }
        mapp[pos]=max(mapp[pos],sum);

        vector<pair<int,int> > op;
        for(auto x:mapp){
            op.push_back(x);
        }
        sort(op.begin(),op.end(),cmp);

        int l=op.size();
        int poss=op[0].first,posl=op[0].second,posn=1,ans=-1;
        for(int i=1;i<l;i++){
            // cout<<op[i].first<<" "<<op[i].second<<endl;
            
        }
    }

    return 0;
}