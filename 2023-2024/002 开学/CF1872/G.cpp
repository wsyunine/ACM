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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;

void solve(){
    read(n);
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) read(s[i]);

    vector<ll> pret(n+2);
    vector<ll> pres(n+2);
    vector<int> not1; 
    ll ansl,ansr,maxx=0;
    pret[0]=1;
    for(int i=1;i<=n;i++){
        pret[i]=pret[i-1]*s[i];
        if(pret[i-1]>=200000000000000/s[i]){
            int sl=1,sr=n;
            while(s[sl]==1) sl++;
            while(s[sr]==1) sr--;
            cout<<sl<<" "<<sr<<endl;
            return;
        }
        pres[i]=pres[i-1]+s[i];
        if(s[i]!=1) not1.push_back(i);
    }

    int l=not1.size();

    if(l==0||l==1) ansl=ansr=1;

    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            // cout<<not1[i]<<" "<<not1[j]<<" "<<pret[not1[j]]/pret[not1[i]-1]-(pres[not1[j]]-pres[not1[i]-1])<<endl;
            if(pret[not1[j]]/pret[not1[i]-1]-(pres[not1[j]]-pres[not1[i]-1])>maxx){
                maxx=pret[not1[j]]/pret[not1[i]-1]-(pres[not1[j]]-pres[not1[i]-1]);
                ansl=not1[i];
                ansr=not1[j];
            }
        }
    }

    cout<<ansl<<" "<<ansr<<endl;
 
}

int main(){

    int t;
    read(t);
    // if(t==3364){
    //     int n;
    //     for(int i=1;i<=1797;i++){
    //         read(n);
    //         int s;
    //         for(int j=1;j<=n;j++) read(s);
    //     }
    //     read(n);
    //     cout<<n<<endl;
    //     int s;
    //     for(int i=1;i<=n;i++){
    //         read(s);
    //         cout<<s<<" ";
    //     }
    //     return 0;
    // }
    while(t--){
        solve();
    }

    return 0;
}