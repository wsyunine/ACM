#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 1000010
using namespace std;

int que[N];
int lp=0,rp=0;

void push(int x){
    que[rp++]=x;
}

void pop(){
    if(lp!=rp) lp++;
    else printf("ERR_CANNOT_POP\n");
}

void qry(){
    if(lp!=rp) printf("%d\n",que[lp]);
    else printf("ERR_CANNOT_QUERY\n");
}

void siz(){
    printf("%d\n",rp-lp);
}

int main(){

    int n,op,x;
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>x;
            push(x);
        }else if(op==2){
            pop();
        }else if(op==3){
            qry();
        }else{
            siz();
        }
    }

    return 0;
}

