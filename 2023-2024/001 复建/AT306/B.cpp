#include<iostream>
using namespace std;

long long ans=0,op=1;

int main(){

    int o;
    for(int i=0;i<=63;i++){
        cin>>o;
        if(o) ans+=op;
        if(i!=63) op<<=1;
        cout<<op<<endl;
    }
    cout<<ans;

    return 0;
}