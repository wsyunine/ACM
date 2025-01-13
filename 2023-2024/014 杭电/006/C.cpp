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

int n;
int t;
string str;
unordered_map<long long,int> mapp;

int main(){

    read(t);
    while(t--){
        mapp.clear();
        read(n);
        cin>>str;
        int id=1,fx=0;//s 0 x 1 z 2 y 3
        int x=100000,y=100000;

        for(int i=0;i<n;i++){
            if(mapp[(long long)x*1000000+(long long)y]==1) id=0;
            mapp[(long long)x*1000000+(long long)y]=1;
            if(str[i]=='S'){
                if(fx==0) x++;
                else if(fx==1) x--;
                else if(fx==2) y--;
                else if(fx==3) y++;
            }else if(str[i]=='L'){
                if(fx==0) y--,fx=2;
                else if(fx==1) y++,fx=3;
                else if(fx==2) x--,fx=1;
                else if(fx==3) x++,fx=0;
            }else{
                if(fx==0) y++,fx=3;
                else if(fx==1) y--,fx=2;
                else if(fx==2) x++,fx=0;
                else if(fx==3) x--,fx=1;
            }
            // cout<<x<<" "<<y<<endl;
        }
        
        if(!id){
            cout<<-1<<endl;
        }else if(x==100000&&y==100000&&fx==0){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }

    return 0;
}