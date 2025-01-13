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

string s;
int sp[N],maxn=0;
char maxs;

int main(){

    cin>>s;
    for(int i=0;i<s.length();i++){
        sp[s[i]]++;
        if(maxn<sp[s[i]]||(maxn==sp[s[i]]&&s[i]<maxs)) maxn=sp[s[i]],maxs=s[i];
    }

    cout<<maxs<<endl;
    
    return 0;
}