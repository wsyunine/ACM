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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
string s;
int a[N],sum[N];
vector<int> res;

signed main(){

    read(n);
    cin>>s;
    for(int i=0;i<n;i++){
        a[i+1]=s[i]%'0';
        sum[i+1]=sum[i]+(i+1)*a[i+1];
    }
    
    for(int i=n;i>=1;i--){
        res.push_back(sum[i]%10);
        sum[i-1]+=sum[i]/10;
    }
    while(sum[0]){
        res.push_back(sum[0]%10);
        sum[0]/=10;
    }

    reverse(res.begin(),res.end());
    for(auto i:res){
        cout<<i;
    }
    cout<<endl;

    return 0;
}