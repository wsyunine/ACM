#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int l,x,y;
string s;
vector<int> op;
vector<pair<short,short>> res,ans;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void ch(int a,int b){
    for(int i=a;i<=b;i++){
        if(s[i]=='0') s[i]='1';
        else s[i]='0';
    }
}

void init(int g){
    int tmp=1;
    res.push_back({tmp-x,tmp-1});
    tmp=tmp-x;
    int d=x-g;
    while(d!=0){
        if(d>=y){
            res.push_back({tmp,tmp+y-1});
            tmp=tmp+y;
            d-=y;
        }else{
            res.push_back({tmp-x,tmp-1});
            tmp=tmp-x;
            d+=x;
        }
    }
}

void mo_r(int a,int b){
    if(b-a+1==x){
        ans.push_back({a,b});
        return;
    }else if(b-a+1==y){
        ans.push_back({a,b});
        return;
    }
    int p=b+1;
    while(p!=a){
        if(p-x>0&&(p>a||p+y>l+1)){
            ans.push_back({p-x,p-1});
            p=p-x;
        }else{
            ans.push_back({p,p+y-1});
            p=p+y;
        }
    }
}

void solve() {
    ans.clear();op.clear();res.clear();
    read(l),read(x),read(y);
    if(y<x) swap(x,y);
    cin>>s;
    int g=gcd(x,y);
    s=' '+s;
    s=s+'3';
    init(g);

    // for(auto i:res) cout<<i.first<<" "<<i.second<<endl;

    for(int i=1;i<=l-x+1;i++){
        if(s[i]=='0'){
            ch(i,i+x-1);
            ans.push_back({i,i+x-1});
        }
    }

    for(int i=l;i>=l-x+1;i--){
        if(s[i]=='0'){
            ch(i-g+1,i);
            op.push_back(i);
        }
    }

    for(int i=1;i<=l;i++){
        if(s[i]=='0'){
            cout<<-1<<endl;
            return;
        }
    }

    for(auto i:op){
        for(auto j:res){
            ans.push_back({j.first+i,j.second+i});
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}