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

int t;
int n;
string pos1,pos2;
int f[2][N],ans=1;
string s;

int main(){

    read(t);
    while(t--){
        read(n);
        ans=0;s.clear();
        cin>>pos1>>pos2;

        int idea=0;
        for(int i=1;i<n;i++){
            if(idea){
                s.push_back(pos2[i-2]);
                continue;
            }
            s.push_back(pos1[i-1]);
            if(pos1[i]=='0'&&pos2[i-1]=='1'){
                ans=0;
            }else if(pos1[i]==pos2[i-1]){
                ans++;
            }else if(pos1[i]=='1'&&pos2[i-1]=='0'){
                idea=1;
                ans++;
            }
        }
        if(idea){
            s.push_back(pos2[n-2]);
            s.push_back(pos2[n-1]);
        }else{
            s.push_back(pos1[n-1]);
            s.push_back(pos2[n-1]);
        }

        if(pos1[n-1]==pos2[n-2]&&!idea) ans++;
        if(!ans) ans++;
        cout<<s<<endl<<ans<<endl;
    }

    return 0;
}