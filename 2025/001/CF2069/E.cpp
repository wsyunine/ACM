#include<bits/stdc++.h>
using namespace std;
#define N 500010
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
string s,t;
int a,b,c,d;

void solve() {
    cin>>s;
    t.clear();
    read(a),read(b),read(c),read(d);

    if(s.size()==1){
        if(s[0]=='A'){
            if(a>=1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            if(b>=1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        return;
    }

    int opa=0,opb=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A') opa++;
        else opb++;
    }
    if(a+c+d<opa||b+d+c<opb){
        cout<<"No"<<endl;
        return;
    }

    t.push_back(s[0]);
    for(int i=1;i<s.size()-1;i++){
        if(s[i]==s[i-1]&&s[i]==s[i+1]){
            if(s[i]=='A') a--;
            else b--;
        }else t.push_back(s[i]);
    }
    t.push_back(s[s.size()-1]);

    int n=t.size();

    if(a<0||b<0){
        cout<<"No"<<endl;
        return;
    }

    int l=0,tmp2=0;
    vector<int> cs,ds;
    t.push_back(t[n-1]);
    for(int i=1;i<=n;i++){
        if(t[i]==t[i-1]){
            if(t[i-1]==t[l]){
                if(t[i-1]=='A') a--;
                else b--;
                tmp2+=(i-1-l+1)/2;
            }else{
                if(t[i-1]=='A'){
                    ds.push_back((i-1-l+1)/2);
                }else cs.push_back((i-1-l+1)/2);
            }
            l=i;
        }
    }

    sort(ds.begin(),ds.end());
    sort(cs.begin(),cs.end());

    for(auto i:cs){
        if(c>=i){
            c-=i;
        }else{
            tmp2+=i-1;
            a--;
            b--;
        }
    }

    for(auto i:ds){
        if(d>=i){
            d-=i;
        }else{
            tmp2+=i-1;
            a--;
            b--;
        }
    }

    if(a<0||b<0){
        cout<<"No"<<endl;
    }else if(c+d>=tmp2){
        cout<<"Yes"<<endl;
    }else if(tmp2-c-d>min(a,b)){
        cout<<"No"<<endl;
    }else cout<<"Yes"<<endl;

}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}