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
int n,k;

void solve() {
    read(n),read(k);

    if(k&1){
        
        for(int i=1;i<n;i++){
            cout<<n<<" ";
        }
        cout<<n-1<<endl;

    }else{
        
        for(int i=1;i<n-1;i++){
            cout<<n-1<<" ";
        }
        cout<<n<<" "<<n-1<<endl;

    }

}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}