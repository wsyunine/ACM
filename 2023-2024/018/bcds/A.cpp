#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define int long long

int t;
int n;
unordered_map<int,int> mapp;

signed main(){

    for(int i=3;i<=1e18;i*=3){
        mapp[i]=1;
    }

    cin>>t;
    while(t--){
        cin>>n;
        int idea=0;
        for(int i=5;i<=n;i*=5){
            if(mapp[n-i]) idea=1;
        }
        if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}