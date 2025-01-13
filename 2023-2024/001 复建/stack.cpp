#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 1000010
using namespace std;

int sz=0;
unsigned long long stk[N];

int siz(){return sz;}

void push(unsigned long long num){
    stk[sz]=num;
    sz++;
    return;
}

void pop(){
    if(!sz) printf("Empty\n");
    else sz--;
    return;
}

void qry(){
    if(!sz) printf("Anguei!\n");
    else{cout<<stk[sz-1]<<endl;}
    return;
}

int main(){

    int k,q;
    unsigned long long x=0;
    char ch[10];
    cin>>k;
    while(k--){
        cin>>q;
        sz=0;
        for(int i=1;i<=q;i++){
            cin>>ch;
            if(ch[0]=='p'&&ch[1]=='u'){
                cin>>x;
                push(x);
            }else if(ch[0]=='p'&&ch[1]=='o'){
                pop();
            }else if(ch[0]=='q'){
                qry();
            }else printf("%d\n",siz());
        }
    }

    return 0;

}