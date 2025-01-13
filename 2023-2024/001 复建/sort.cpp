#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 1000010
using namespace std;

int num[N],n;

bool cmp(int a,int b){
    return a<b;
}

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    return 0;
}
