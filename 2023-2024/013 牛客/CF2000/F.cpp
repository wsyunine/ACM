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
int t,k;
pair<int,int> s[N];
int l[N],yt[N],ans=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; 

int main(){

    read(t);
    while(t--){
        read(n);read(k);ans=0;
        for(int i=1;i<=n;i++){
            read(s[i].first),read(s[i].second);
            if(s[i].first>s[i].second) swap(s[i].first,s[i].second);
        }
        sort(s+1,s+1+n);

        int op=1;
        for(;k>=s[op].first+s[op].second&&op<=n;op++){
            ans+=s[op].first*s[op].second;
            k-=s[op].first+s[op].second;
        }

        if(op>n&&k){
            cout<<-1<<endl;
            continue;
        }

        int cb=s[op].second;
        while(cb>s[op].first){
            k--;
            cb--;
            ans+=s[op].first;
            if(!k) break;
        }
        if(!k){
            cout<<ans<<endl;
        }else{
            ans+=s[op].first;
            k--;
            if(!k) cout<<ans<<endl;
            else{
                for(int i=s[op].first-1;i>=0;i--){
                    k--;
                    ans+=i;
                    if(!k) break;
                    k--;
                    ans+=i;
                    if(!k) break;
                }
                cout<<ans<<endl;
            }
            
        }

        // for(int i=0;i<n;i++){
        //     for(int j=1;j<=l[2*i];j++) q.push(make_pair(l[2*i+1],2*i));
        //     for(int j=1;j<=l[2*i+1];j++) q.push(make_pair(l[2*i],2*i+1));
        // }
        // for(int i=1;i<=k;i++){
        //     auto tt=q.top();
        //     while(1){
        //         q.pop();
        //         if(tt.first==l[tt.second^1]-yt[tt.second]) break;
        //         q.push(make_pair(l[tt.second^1]-yt[tt.second],tt.second));
        //         tt=q.top();
        //     }
        //     ans+=tt.first;
        //     yt[tt.second^1]++;
        // }
        // cout<<ans<<endl;
    }

    return 0;
}