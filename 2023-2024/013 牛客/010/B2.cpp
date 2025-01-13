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
#include<unordered_map>
using namespace std;
#define N 1000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,q;
string cs[1010],s;
unordered_map<string,int> mapp;
int tr[N][2],cnt=0,f[N];
pair<int,int> num[N];

void out(string u){
    int len=u.length();
    string ss,up;
    int l=0;
    for(int i=0;i<len;i++){
        if(u[i]=='.'){
            if(!l) l=mapp[ss],up=cs[l],ss.clear();
            else{
                if(ss[0]=='f') l=tr[l][0];
                else l=tr[l][1];
                ss.clear();
            }
            // cout<<l<<endl;
        }else ss.push_back(u[i]);
    }
    if(!l) l=mapp[ss],up=cs[l],ss.clear();
    else{
        if(ss[0]=='f') l=tr[l][0];
        else l=tr[l][1];
    }
    // cout<<l<<endl;
    // cout<<num[l].first<<" "<<num[l].second<<endl;
    cout<<up.substr(num[l].first,num[l].second-num[l].first+1)<<endl;
}

int main(){

    read(n),read(q);
    for(int i=1;i<=n;i++){
        cin>>cs[i];
        cin>>s;
        mapp[s.substr(0,s.length()-1)]=i;
    }
    cnt=n;
    stack<int> sta;
    for(int i=1;i<=n;i++){
        int l=i;
        sta.push(0);
        for(int j=0;j<cs[i].length();j++){
            if(cs[i][j]=='<'){
                sta.push(j+1);
                if(!tr[l][0]) tr[l][0]=++cnt,f[cnt]=l;
                l=tr[l][0];
            }else if(cs[i][j]==','){
                num[l]={sta.top(),j-1};
                sta.pop();
                l=f[l];
                sta.push(j+1);
                if(!tr[l][1]) tr[l][1]=++cnt,f[cnt]=l;
                l=tr[l][1];
            }else if(cs[i][j]=='>'){
                num[l]={sta.top(),j-1};
                sta.pop();
                l=f[l];
            }
        }
        num[l]={sta.top(),cs[i].length()-1};
        sta.pop();
    }

    // for(int i=1;i<=cnt;i++) cout<<num[i].first<<" "<<num[i].second<<endl;

    while(q--){
        cin>>s;
        out(s);
    }

    // for(int i=1;i<=cnt;i++) cout<<i<<" "<<tr[i][0]<<" "<<tr[i][1]<<endl;

    return 0;
}