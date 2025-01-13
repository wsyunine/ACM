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
#define N 300010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int t;
int a[N];
string b;
unordered_map<char,int> mapp;
unordered_map<int,char> sum;

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);

        read(m);
        while(m--){
            mapp.clear();
            sum.clear();
            cin>>b;
            int l=b.length();
            if(l!=n){
                cout<<"NO"<<endl;
                continue;
            }
            int id=1;
            for(int i=0;i<l;i++){
                if(!mapp[b[i]]){
                    mapp[b[i]]=a[i+1];
                    if(sum[a[i+1]]){id=0;break;}
                    sum[a[i+1]]=b[i];
                }
                if(mapp[b[i]]!=a[i+1]||sum[a[i+1]]!=b[i]){
                    id=0;
                    break;
                }
            }
            if(id) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}