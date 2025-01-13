#include<iomanip>
#include<iostream>
#include<string.h>
using namespace std;
#define N 100010
#define int __int128 
int n;
int lll,llr,rrl,rrr;
template<typename T>
inline void read(T &x,int ip=0){
    x=0;bool flg=0;char c=getchar();
    int s=0;
    if(ip==1){
        for(;!isdigit(c);c=getchar(),s++) if(c=='-') flg=1;
        for(;isdigit(c),s<=n-1;c=getchar(),s++) x=x*10+(c^48);
        if(flg) x=-x;
        lll=x;
        x=0;flg=0;
        for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
        for(;isdigit(c);c=getchar()) x=x*10+(c^48);
        if(flg) x=-x;
        llr=x;
        return;
    }else if(ip==2){
        for(;!isdigit(c);c=getchar(),s++) if(c=='-') flg=1;
        for(;isdigit(c),s<=n-1;c=getchar(),s++) x=x*10+(c^48);
        if(flg) x=-x;
        rrl=x;
        x=0;flg=0;
        for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
        for(;isdigit(c);c=getchar()) x=x*10+(c^48);
        if(flg) x=-x;
        rrr=x;
        return;
    }
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
void print(__int128 num) {
	if (num > 9) print(num / 10);
	putchar(num % 10 + '0');
}

int l,r;

int b_s_upper(int ll,int rr,int s){
    while(ll<rr){
        int mid=(ll+rr)>>1;
        if(mid*mid>s) rr=mid;
        else ll=mid+1;
    }
    return ll;
}

int b_s_lower(int ll,int rr,int s){
    while(ll<rr){
        int mid=(ll+rr)>>1;
        if(mid*mid>=s) rr=mid;
        else ll=mid+1;
    }
    return ll;
}

signed main(){

    read(n);
    n/=2;
    read(l,1),read(r,2);
    print(lll),cout<<endl;
    print(llr),cout<<endl;
    print(rrl),cout<<endl;
    print(rrr),cout<<endl;
    int op=1;
    for(int i=1;i<=n;i++) op=op*10;
    int op0=pow(10,n/2+2);
    print(op),cout<<endl;

    int sum=b_s_upper(0,op0,op-1)-1;
    // print(sum);cout<<endl;
    
    int l1=b_s_lower(0,op0,lll);
    int r1=b_s_upper(0,op0,rrl)-1;
    // print(l1);cout<<endl;
    // print(r1);cout<<endl;

    int id1=0,id2=0;
    if(l1*l1==lll) id1=1;
    if(r1*r1==rrl) id2=1;

    int l2,r2;
    if(id1) l2=b_s_lower(0,op0,llr);
    if(id2) r2=b_s_upper(0,op0,rrr)-1;
    // print(l2);cout<<endl;
    // print(r2);cout<<endl;

    if(!id1&&!id2) print((r1-l1+1)*(sum-0+1));
    else if(id1&&!id2) print((r1-l1)*(sum-0+1)+(sum-l2+1));
    else if(!id1&&id2) print((r1-l1)*(sum-0+1)+(r2-0+1));
    else if(id2&&id2) print((r1-l1-1)*(sum-0+1)+(r2-0+1)+(sum-l2+1));

    printf("\n");

    return 0;
}

/*

60 
100000000000000000000000000000000000000000000000000000000000 999999999999999999999999999999999999999999999999999999999999

*/