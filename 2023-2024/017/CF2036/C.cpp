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
int a[N];
string str;
int st[N],tmp[N],sum[5];
int q;

int check(int l){
    int op=0;
    if(st[l]==1){
                op=1;
                if(st[l+1]==1){
                    op=2;
                    if(st[l+2]==0){
                        op=3;
                        if(st[l+3]==0){
                            op=4;
                        }
                    }
                }
            }
    return op;
}

int main(){

    read(t);
    while(t--){
        cin>>str;
        sum[0]=sum[1]=sum[2]=sum[3]=sum[4]=0;
        for(int i=1;i<=str.length();i++){
            st[i]=(str[i-1]=='1'?1:0);
        }
        n=str.length();
        st[n+1]=-1;
        st[n+2]=-1;
        st[n+3]=-1;

        for(int i=1;i<=n;i++){
            tmp[i]=0;
            if(st[i]==1){
                tmp[i]=1;
                if(st[i+1]==1){
                    tmp[i]=2;
                    if(st[i+2]==0){
                        tmp[i]=3;
                        if(st[i+3]==0){
                            tmp[i]=4;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) sum[tmp[i]]++;

        read(q);
        while(q--){
            int l,r;
            read(l),read(r);
            st[l]=r;
            sum[tmp[l]]--;
            //cout<<check(l)<<endl;
            tmp[l]=check(l);
            sum[tmp[l]]++;
            if(l-1>0){
                sum[tmp[l-1]]--;
                tmp[l-1]=check(l-1);
                sum[tmp[l-1]]++;
            }
            if(l-2>0){
                sum[tmp[l-2]]--;
                tmp[l-2]=check(l-2);
                sum[tmp[l-2]]++;
            }
            if(l-3>0){
                sum[tmp[l-3]]--; 
                tmp[l-3]=check(l-3);
                sum[tmp[l-3]]++;
            }
            if(sum[4]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

    return 0;
}