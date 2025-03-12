#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
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
string str;
int cnt=0;

void solve() {
    cin>>str;cnt=0;
    for(int i=str.size()-1;i>=0;i--){
        if(i>=1&&str[i]==str[i-1]){
            break;
        }else cnt++;
    }
    if(cnt!=str.size()) cnt=1;
    cout<<cnt<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}