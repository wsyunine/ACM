#include<string.h>
#include<math.h>
#include<stdio.h>
#define N 100010
#define int __int128 
int n;
int lll,llr,rrl,rrr;
int read(int ip)
{   
    if(ip==1){
        int x = 0,s=0;
        char c = getchar();
        while (c < 48 || c > 57)
            c = getchar();
        while (c > 47 && c < 58&&s<=n-1)
            s++,x = (x << 1) + (x << 3) + c - 48, c = getchar();
        lll=x;x=0;
        while (c < 48 || c > 57)
            c = getchar();
        while (c > 47 && c < 58)
            s++,x = (x << 1) + (x << 3) + c - 48, c = getchar();
        llr=x;x=0;
        return x;
    }else if(ip==2){
        int x = 0,s=0;
        char c = getchar();
        while (c < 48 || c > 57)
            c = getchar();
        while (c > 47 && c < 58&&s<=n-1)
            s++,x = (x << 1) + (x << 3) + c - 48, c = getchar();
        rrl=x;x=0;
        while (c < 48 || c > 57)
            c = getchar();
        while (c > 47 && c < 58)
            s++,x = (x << 1) + (x << 3) + c - 48, c = getchar();
        rrr=x;x=0;
        return x;
    }
	int x = 0;
	char c = getchar();
	while (c < 48 || c > 57)
		c = getchar();
	while (c > 47 && c < 58)
		x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x;
}

void print(int num) {
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

    // print(1);
    n=read(0);
    n/=2;
    l=read(1),r=read(2);
    // print(lll);printf("\n");
    // print(llr);printf("\n");
    // print(rrl);printf("\n");
    // print(rrr);printf("\n");
    int op=1,op0=1;
    for(int i=1;i<=n;i++) op=op*10;
    for(int i=1;i<=n/2+2;i++) op0=op0*10;

    int sum=b_s_upper(0,op0,op-1)-1;
    // print(sum);printf("\n");
    
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
    // print(l2);printf("\n");
    // print(r2);printf("\n");

    if(!id1&&!id2) print((r1-l1+1)*(sum-0+1));
    else if(id1&&!id2) print((r1-l1)*(sum-0+1)+(sum-l2+1));
    else if(!id1&&id2) print((r1-l1)*(sum-0+1)+(r2-0+1));
    else if(id2&&id2) print((r1-l1-1)*(sum-0+1)+(r2-0+1)+(sum-l2+1));

    printf("\n");

    return 0;
}