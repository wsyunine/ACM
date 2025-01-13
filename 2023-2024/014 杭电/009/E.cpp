#include<iostream>
using namespace std;
// template<typename T>
// inline void read(T &x){
//     x=0;bool flg=0;char c=getchar();
//     for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
//     for(;isdigit(c);c=getchar()) x=x*10+(c^48);
//     if(flg) x=-x;
// }

int t;
long long k,x,y;

int main(){

    scanf("%d",&t);
    while(t--){
        int id0=0,id1=0;
        scanf("%lld %lld %lld",&k,&x,&y);
        // read(k),read(x),read(y);
        // if(x>y) swap(x,y);
        // if(x==1&&y==1){
        //     if(k%2) printf("Yes\nNo");
        //     else printf("No\nYes");
        //     continue;
        // }else if(x==1){
        //     printf("Yes\nNo");
        //     continue;
        // }else if(y==2){
        //     if(k%2) k=k+1;
        //     k=k/2;
        //     if(k%2) printf("Yes\nNo");
        //     else printf("No\nYes");
        //     continue;
        // }
        // long long op=k%y==0?k/y:k/y+1;
        // long long op1=(op-x)%y==0?(op-x)/y:(op-x)/y+1;
        // if(op%2) id1=1;
        // else id0=1;
        // if((op+1)%2) id1=1;
        // else id0=1;
        // op=k%x==0?k/x:k/x+1;
        // op1=op*x;
        // if(op%2) id1=1;
        // else id0=1;
        // while(op1<k&&op1+y>=k) op1-=x,op--;
        // if((op+1)%2) id1=1;
        // else id0=1;

        if(id1) printf("Yes\n");
        else printf("No\n");
        if(id0) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}