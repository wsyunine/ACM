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

int n;
int t;
int k,a[N];

struct stdd{
    multiset<int> s1,s2;
    int sum1,sum2,h1,h2;

    void id(){
        sum1=0;sum2=0;
        s1.clear();
        s2.clear();
    }

    void insert(int x){
        int tmp=*(--s1.end()),ss1,ss2;
        if(sum1==sum2) ss1=sum1+1,ss2=sum2;
        else ss1=sum1,ss2=sum2+1;

        if(x>tmp) s1.erase(tmp),s2.insert(tmp),s1.insert(x);
        while(s1.size()<ss1){
            int op=*s2.begin();
            s1.insert(op);
            s2.erase(op);
        }

        sum1=ss1;
        sum2=ss2;
    }

    void pop(int x){
        int tmp=*(--s1.end()),ss1,ss2;
        if(sum1==sum2) ss1=sum1+1,ss2=sum2;
        else ss1=sum1,ss2=sum2+1;

        if(x>tmp) s1.erase(tmp),s2.insert(tmp),s1.insert(x);
        while(s1.size()<ss1){
            int op=*s2.begin();
            s1.insert(op);
            s2.erase(op);
        }

        sum1=ss1;
        sum2=ss2;
    }
};

int main(){

    read(t);

    while(t--){
        read(n);read(k);
        set<int> s;
        for(int i=1;i<=n;i++) read(a[i]),a[i]=a[i]-i;

        int pos=0;
        for(int i=1,j=1;i<=n;i++){
            while()
        }

        cout<<l<<endl;
    }
    

    return 0;
}