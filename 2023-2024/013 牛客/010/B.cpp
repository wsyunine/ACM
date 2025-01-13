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
#define N 800010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int q;
string s;
unordered_map<string,int> mapp;
int tr[N][2],cnt=0;
string cs[1010];
pair<int,int> num[N];

int rd(string u,int po,int l,int r){
    int t=po?po:++cnt;
    // cout<<t<<" "<<l<<" "<<r<<endl;
    int len=u.length();
    if(u[l]=='p'){
        int pp=0;
        for(int i=l+5;i<=r-1;i++){
            if(u[i]=='<') pp++;
            else if(u[i]=='>') pp--;
            if(pp==0&&u[i]==','){
                tr[t][0]=rd(u,0,l+5,i-1);
                tr[t][1]=rd(u,0,i+1,r-1);
                break;
            }
        }
    }
    num[t]={l,r};
    return t;
}

void out(string u){
    int len=s.length();
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

    read(n);read(q);
    for(int i=1;i<=n;i++){
        cin>>cs[i];
        cin>>s;
        mapp[s.substr(0,s.length()-1)]=i;
    }
    cnt=n;
    for(int i=1;i<=n;i++){
        rd(cs[i],i,0,cs[i].length()-1);
    }

    // for(int i=1;i<=cnt;i++) cout<<i<<" "<<tr[i][0]<<" "<<tr[i][1]<<endl;

    while(q--){
        cin>>s;
        out(s);
    }

    return 0;
}
/*

3 3
int a;
pair<int,int> E6;
pair<pair<double,int>,double> __Fukami;
a
E6
__Fukami.first.second

*/