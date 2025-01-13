#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug() puts("I WILL AK")
#define N 11

mt19937 rnd(time(0));
int ct;
#define M 25
int a[M];
signed main(){
	//freopen(".in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("data.in","w",stdout);
	int T=5;
	cout<<5<<'\n';
	while(T--){
		int n,m,l,v;
		n=5,m=5,l=(long long)rnd()%N+5,v=(long long)rnd()%M+1;
		cout<<n<<' '<<m<<' '<<l<<' '<<v<<'\n';
		for(int i=1;i<=n;++i){
			cout<<((long long)rnd()%(l+1))<<' '<<((long long)rnd()%N+4)<<' '<<((long long)rnd()%N-5)<<'\n';
		}
		for(int i=1;i<=l;++i){
			a[i]=i;
		}
		shuffle(a+1,a+l+1);
		sort(a+1,a+m+1);
		for(int i=1;i<=m;++i){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}
	
	return 0;
}