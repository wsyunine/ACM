#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#define N 1000010
using namespace std;

priority_queue<int,vector<int>,greater<int> > que;

int main(){

    int n,op,x;
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>x;
            que.push(x);
        }else if(op==2){
            cout<<que.top()<<endl;
        }else{
            que.pop();
        }
    }

    return 0;
}