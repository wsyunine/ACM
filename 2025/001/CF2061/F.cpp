
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <thread>
#include <vector>
using namespace std;
#define N 500010
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
string s,t;
int pre[N];

void solve() {
    cin>>s>>t;
    int len=s.size(),a=0,b=0,op1=(s[0]=='0'),op2=(t[0]=='0');
    char op=s[0];
    for(int i=1;i<len;i++){
        if(s[i]=='0') op1++;
        if(op!=s[i]){
            op=s[i];
            a++;
        }
    }
    op=t[0];
    for(int i=1;i<len;i++){
        if(t[i]=='0') op2++;
        if(op!=t[i]){
            op=t[i];
            b++;
        }
    }

    if(op1!=op2){
        cout<<-1<<endl;
        return;
    }
    if(a<b){
        cout<<-1<<endl;
        return;
    }

    pre[len]=0;
    s.push_back('?');
    for(int i=len-1;i>=0;i--){
        if(s[i]==s[i+1]) pre[i]=pre[i+1]+1;
        else pre[i]=1;
    }

    int opt=0;
    for(int i=0;i<len;i++){
        if(s[i]==t[i]){
            continue;
        }else{
            if(s[i]==s[i-1]){
                cout<<"-1"<<endl;
                return;
            }else{
                int sp=i,lp=i,cnt=0;
                while(sp<len&&t[sp]==t[sp+1]) sp++;
                while(lp<len&&cnt<sp-i+1){
                    if(s[lp+1]==t[i]) cnt++;
                    if(s[lp+1]==t[i]&&s[lp]!=s[lp+1]) opt++;
                    lp++;
                }
                if(cnt<sp-i+1){cout<<-1<<endl;return;}
                if(lp<len&&s[lp+1]==t[i]){cout<<-1<<endl;return;}
                for(int j=i;j<=sp;j++) s[j]=t[i];
                for(int j=sp+1;j<=lp;j++) s[j]=(t[i]=='0'?'1':'0');
            }
        }
        // cout<<s<<endl;
    }

    cout<<opt<<endl;
    
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
