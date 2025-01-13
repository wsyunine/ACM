#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int a,b,x,y;
int vis[300],d[300];

int main(){

    cin>>a>>b>>x>>y;

    if(a==b){
        cout<<x<<endl;
    }else if(a<b){
        if(2*x<y){
            cout<<x+(b-a)*2*x<<endl;
        }else cout<<x+(b-a)*y<<endl;
    }else if(a>b){
        if(2*x<y){
            cout<<x+(a-b-1)*2*x<<endl;
        }else cout<<x+(a-b-1)*y<<endl;
    }

    return 0;
}