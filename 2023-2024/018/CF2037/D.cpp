#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,m,L;
vector<pair<int,int>> ih;
priority_queue<int> q;

int main(){

    read(t);
    while(t--){
        while(q.size()) q.pop();
        ih.clear();

        read(n),read(m);
        read(L);
        for(int i=1;i<=n;i++){
            int a,b;
            read(a),read(b);
            ih.push_back({a,b-a+2});
        }

        for(int i=1;i<=m;i++){
            int a,b;
            read(a),read(b);
            ih.push_back({a,-b});
        }
        sort(ih.begin(),ih.end());

        int res=0;
        long long tmp=1;
        int idea=1;
        for(auto i:ih){
            if(i.second<0){
                q.push(-i.second);
            }else{
                while(q.size()&&tmp<i.second){
                    tmp+=q.top();
                    q.pop();
                    res++;
                }
                if(tmp<i.second){
                    idea=0;
                    break;
                }
            }
        }

        if(idea) cout<<res<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}