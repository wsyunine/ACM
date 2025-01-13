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
int t;
int m,hp,dmg;
int ans[N];

int main(){

    read(t);
    while(t--){
        read(n),read(m),read(hp),read(dmg);
        for(int i=1;i<=m;i++) ans[i]=0;

        cout<<"+";
        for(int i=1;i<=m;i++) cout<<"-";
        cout<<"+"<<endl;

        int s1=hp/m,k=(hp-1)/m+1;
        int s2=hp%m,mop;
        vector<int> q;
        q.push_back(0);
        if(s1){
            mop=m;
            for(int i=s2+1;i<=m;i++) q.push_back(i),ans[i]=s1;
            for(int i=1;i<=s2;i++) q.push_back(i),ans[i]=s1+1;
        }else{
            mop=s2;
            for(int i=1;i<=s2;i++) q.push_back(i),ans[i]=s1+1;
        }
        int op=max(1,mop-dmg+1);
        for(int i=op;i<=mop;i++) ans[q[i]]=-1;
        for(int j=1;j<=n;j++){
            cout<<"|";
            for(int i=1;i<=m;i++){
                if(ans[i]==-1){
                    cout<<".";
                }else if(ans[i]==0){
                    cout<<" ";
                }else if(ans[i]%5==1){
                    cout<<"A";
                }else if(ans[i]%5==2){
                    cout<<"B";
                }else if(ans[i]%5==3){
                    cout<<"C";
                }else if(ans[i]%5==4){
                    cout<<"D";
                }else if(ans[i]%5==0){
                    cout<<"E";
                }
            }
            cout<<"|"<<endl;
        }
        // for(int i=k+2;i<=n;i++){
        //     cout<<"|";
        //     for(int j=1;j<=m;j++) cout<<" ";
        //     cout<<"|"<<endl;
        // }
        
        cout<<"+";
        for(int i=1;i<=m;i++) cout<<"-";
        cout<<"+"<<endl;
    }

    return 0;
}