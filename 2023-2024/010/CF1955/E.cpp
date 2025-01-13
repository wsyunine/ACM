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

int n;
int t;
string str;
vector<int> a(N),b(N);

int main(){

    read(t);
    while(t--){
        read(n);
        cin>>str;
        for(int i=1;i<=n;i++) a[i]=str[i-1]-'0';

        for(int i=n;i>=1;i--) a[i]=a[i]-a[i-1];
        
        b=a;

        bool idea=1;
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int i=1,k=b[1];i<=n;i++,k+=b[i]){
                // cout<<k<<" ";
                if(k%2==0){
                    if(i+j>n+1){idea=0;break;}
                    k++;
                    b[i+j]--;
                }
            }
            // cout<<endl;
            if(idea) ans=max(ans,j);
            idea=1;
            for(int i=1;i<=n;i++) b[i]=a[i];
            
        }

        cout<<ans<<endl;
        
    }

    return 0;
}