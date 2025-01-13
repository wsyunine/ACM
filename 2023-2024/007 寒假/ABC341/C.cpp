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

int h,w,n,res=0;
string str;
int mapp[501][501];

int main(){

    read(h);read(w);read(n);

    cin>>str;
    
    for(int i=1;i<=h;i++){
        string s;
        cin>>s;
        for(int j=1;j<=w;j++){
            if(s[j-1]=='.') mapp[i][j]=1;
            else mapp[i][j]=0;
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int posx=i,posy=j;
            bool idea=1;
            for(int k=1;k<=n;k++){
                if(!mapp[posx][posy]){idea=0;break;}
                if(str[k-1]=='L') posy--;
                if(str[k-1]=='R') posy++;
                if(str[k-1]=='U') posx--;
                if(str[k-1]=='D') posx++;
            }
            if(!mapp[posx][posy]) idea=0;
            if(idea) res++;
        }
    }

    cout<<res<<endl;

    return 0;
}