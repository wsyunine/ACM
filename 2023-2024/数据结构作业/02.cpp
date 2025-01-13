#include<iostream>
#include<cstdio>
#define maxn 100010
using namespace std;
template<typename T>
inline void read(T &x){
	x=0; bool flag=0; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') flag=1;
	for(;isdigit(c);c=getchar()) x=x*10+(c^48);
	if(flag) x=-x;
}

const int inf=0x3f3f3f3f;
int n,op,x;
int rt,tot,fa[maxn],cnt[maxn],val[maxn],siz[maxn];
int ch[maxn][2];//0->left 1->rignt

bool check(int x){
	return ch[fa[x]][1]==x;
}

void pushup(int x){
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+cnt[x];
}

void rotate(int x){
	int y=fa[x],z=fa[y],k=check(x),w=ch[x][k^1];
	ch[z][check(y)]=x,ch[x][k^1]=y,ch[y][k]=w;
	fa[x]=z,fa[y]=x,fa[w]=y;
	pushup(y),pushup(x);
}

void splay(int x,int goal){
	for(;fa[x]!=goal;rotate(x)){
		int y=fa[x];
		if(fa[y]!=goal) rotate(check(x)^check(y)?x:y);
	}
	if(!goal) rt=x;
}

void insert(int x){
	int cur=rt,f=0;
	while(cur&&val[cur]!=x) f=cur,cur=ch[cur][val[cur]<x];
	if(cur) cnt[cur]++;
	else{
		cur=++tot;
		ch[f][val[f]<x]=cur;
		fa[cur]=f,val[cur]=x,cnt[cur]=1;
	}
	splay(cur,0);
}

void find(int x){
	int cur=rt;
	while(ch[cur][val[cur]<x]&&x!=val[cur]) cur=ch[cur][val[cur]<x];
	splay(cur,0);
}

int rank_(int x){//rank 变量名冲突 
	find(x);
	return siz[ch[rt][0]];
}

int query(int x){
	x++;
	int cur=rt;
	while(1){
		if(x<=siz[ch[cur][0]]) cur=ch[cur][0];
		else{
			x-=siz[ch[cur][0]]+cnt[cur];
			if(x<=0) return val[cur];
			cur=ch[cur][1];
		}
	}
}

int from(int x){
	find(x);
	if(val[rt]<x) return rt;
	int cur=ch[rt][0];
	while(ch[cur][1]) cur=ch[cur][1];
	return cur;
}

int nxt(int x){
	find(x);
	if(val[rt]>x) return rt;
	int cur=ch[rt][1];
	while(ch[cur][0]) cur=ch[cur][0];
	return cur;
}

void del(int x){
	int fromm=from(x),nxtt=nxt(x);
	splay(fromm,0);splay(nxtt,fromm);
	int t=ch[nxtt][0];
	if(cnt[t]>1) cnt[t]--,splay(t,0);
	else ch[nxtt][0]=0;
}

signed main(){
	read(n);
	insert(inf);insert(-inf);
	for(int i=1;i<=n;i++){
		read(op),read(x);
		if(op==1) insert(x);
		if(op==2) del(x);
		if(op==3) printf("%d\n",rank_(x));
		if(op==4) printf("%d\n",query(x));
		if(op==5) printf("%d\n",val[from(x)]);
		if(op==6) printf("%d\n",val[nxt(x)]);

        for(int i=1;i<=siz[];i++){
            cout<<
        }

	}
	return 0;
}//splay
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
//
106465
84185
492737
*/