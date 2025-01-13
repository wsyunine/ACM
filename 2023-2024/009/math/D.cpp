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

int t;
int n,m;
string str1,str2;

string cutt(string s,int l,int r){
    string ans;
    for(int i=0;i<l;i++) ans.push_back(s[i]);
    for(int i=r+1;i<s.length();i++) ans.push_back(s[i]);
    return ans;
}

string xiao(string s){
    while(1){
        int sop=0,l=0;bool is=0;
        for(int i=0;i<s.length();i++){
            sop++;
            if(s[i+1]!=s[i]){
                if(sop>=3){
                    s=cutt(s,l,i);
                    is=1;
                    continue;
                }
                sop=0;
                l=i+1;
            }
        }
        if(!is) break;
    }
    return s;
}

int dfs(string s,int l,int sum){
    if(s.length()==0) return sum;
    if(l>=m) return 0x3f3f3f3f;
    string op;int li=0,up=0;
    int mx=0x3f3f3f3f;
    for(int i=0;i<=n;i++){
        if(s[i]==str2[l]) up++;
        else{
            if(up>=2){
                op=cutt(s,li,i-1);
                op=xiao(op);
                mx=min(dfs(op,l+1,sum+1),mx);
            }
            li=i+1;
            up=0;
        }
    }
    return mx;
}

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        cin>>str1>>str2;
        
        int ansop=dfs(str1,0,0);
        if(ansop!=0x3f3f3f3f){
            cout<<ansop<<endl;
        }else cout<<"lose"<<endl;
    }

    return 0;
}