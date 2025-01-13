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

int t;
int n;
string s;
int idea=0;

int main(){

    read(t);
    while(t--){
        read(n);
        cin>>s;

        idea=0;
        int len=s.length();
        for(int i=0,j=len-1;i<j;i++,j--){
            if(s[j]<s[i]){idea=1;break;}
            else if(s[i]<s[j]){idea=0;break;}
        }

        if(idea){
            if(n%2){
                reverse(s.begin(),s.end());
                cout<<s<<endl;
            }else{
                reverse(s.begin(),s.end());
                cout<<s;
                reverse(s.begin(),s.end());
                cout<<s<<endl;
            }
        }else{
            if(n%2){
                cout<<s;
                reverse(s.begin(),s.end());
                cout<<s<<endl;
            }else{
                cout<<s<<endl;
            }
        }
    }

    return 0;
}