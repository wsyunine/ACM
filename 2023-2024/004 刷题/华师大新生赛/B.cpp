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
#define N 1000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,q,k,p,st;
vector<int> s;
int mapp[N];

int ope(int x){
    vector<int> num1;
    int n1=0,n2=0;
    for(int i=1;i<=n;i++){
        num1.push_back(x%10);
        x/=10;
    }
    sort(num1.begin(),num1.end());
    for(int i=1;i<=n;i++){
        n1+=num1[i-1];n1*=10;
        n2+=num1[n-i];n2*=10;
    }
    n1/=10,n2/=10;
    return n2-n1;
}

void print(int x){
    vector<int> num1;
    for(int i=1;i<=n;i++){
        num1.push_back(x%10);
        x/=10;
    }
    for(int i=n-1;i>=0;i--){
        cout<<num1[i];
    }
    cout<<endl;
}

int main(){

    memset(mapp,-1,sizeof mapp);
    read(n),read(q),read(k);
    
    int pos=q;
    p=0;
    while(mapp[pos]==-1){
        s.push_back(pos);
        mapp[pos]=p;
        pos=ope(pos);
        p++;
    }
    st=mapp[pos];
    p=p-mapp[pos];

    if(k<st+p){
        pos=q;
        while(k--){
            pos=ope(pos);
        }
        print(pos);
        return 0;
    }else{
        k=(k-st)%p+st;
        print(s[k]);
        return 0;
    }

    return 0;
}