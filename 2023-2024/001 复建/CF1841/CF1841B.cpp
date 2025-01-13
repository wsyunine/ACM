#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=2000000;

int n,q;

int main() {

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q;
        int op=0,l1,r1,l2,r2,num;
        cin>>l1;r1=l1;
        printf("1");
        for(int j=2;j<=q;j++){
            cin>>num;
            if(!op){
                if(num<r1) if(num>l1){cout<<0;continue;}
                if(num<r1) if(num<=l1){cout<<1;op=1;l2=num;r2=num;continue;}
                if(num>=r1){r1=num;cout<<1;continue;}
            }else{
                if(num<r2){cout<<0;continue;}
                if(num>l1){cout<<0;continue;}
                if(num>=r2){cout<<1;r2=num;continue;}
            }
        }
        cout<<endl;
    }

    return 0;
}