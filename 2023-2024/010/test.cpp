#include<iostream>
using namespace std;
int main(){

    double a,b;
    double ans=0;
    cin>>a>>b;
    double l=a,r=a+(b-a)/1000;
    for(;r<=b;l+=(b-a)/1000,r+=(b-a)/1000){
        ans+=(2+2*l*l+3*l*l*l+2*r*r+3*r*r*r)*((b-a)/1000)/2;
    }
    cout<<ans<<endl;

    return 0;
}
