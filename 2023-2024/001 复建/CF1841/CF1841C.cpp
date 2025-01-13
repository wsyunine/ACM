#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=200010;

int n;
int num[10]={1,10,100,1000,10000};
char q[N];
int l[10],r[10];
long long ans=0;

long long cal(int le){
    long long op=0;
    int s=-1,o=-1;
    for(int i=le-1;i>=0;i--){
        o=q[i]-65;
        if(o>=s) op+=num[o],s=o;
        else op-=num[o];
    }
    return op;
}

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q;
        int len=strlen(q);
        ans=cal(len);
        for(int j=0;j<=4;j++) r[j]=-1,l[j]=-1;
        for(int j=0;j<=len-1;j++) r[q[j]-65]=j;
        for(int j=len-1;j>=0;j--) l[q[j]-65]=j;
        for(int j=0;j<=4;j++){
            if(l[j]==-1) continue;
            for(int k=j+1;k<=4;k++){
                q[l[j]]=k+65;
                ans=max(ans,cal(len));
                q[l[j]]=j+65;
            }
            for(int k=0;k<j;k++){
                q[r[j]]=k+65;
                ans=max(ans,cal(len));
                q[r[j]]=j+65;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}