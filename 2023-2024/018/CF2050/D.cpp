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
string s;
int a[N];
pair<int,int> sp[N];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first==b.first?a.second>b.second:a.first>b.first;
}

int main(){

    read(t);
    while(t--){
        cin>>s;
        for(int i=1;i<=s.length();i++){
            a[i]=s[i-1]%'0';
        }

        for(int i=1;i<=s.length();i++){
            int j=i-1,k=i;
            while(j>0&&a[j]<a[k]-1){
                a[k]--;
                swap(a[j],a[k]);
                j--;k--;
            }
        }

        for(int i=1;i<=s.length();i++) cout<<a[i];
        cout<<endl;

    }

    return 0;
}