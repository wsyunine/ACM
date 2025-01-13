#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==1||a>=5) cout<<"Alice"<<endl;
        else if(a==2||a==3||a==4) cout<<"Bob"<<endl;
    }

    return 0;
}