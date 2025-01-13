#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int n,q;
int p[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main(){
    cin>>n>>q;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;i++)cin>>p[i];
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;

    }
    //哪个b爱想谁想，我要写我的线代作业、、
    //还是吃多点好的，睡多点，梦里啥都有

}