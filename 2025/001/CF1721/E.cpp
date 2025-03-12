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
string c,str[N];
pair<int,int> num[N];
vector<int> s[N];
int len;
int q,nxt[1000050];

bool cmp(pair<int,int> a,pair<int,int> b){
    return str[a.first]<str[b.first];
}

char SStr(int x,int id){
    if(x<=len) return c[x];
    else return str[id][x-len];
}

void solve() {
    cin>>c;
    c=' '+c;
    len=c.size()-1;
    for(int i=2,j=0;i<c.size();i++){
        while(j&&c[j+1]!=c[i]) j=nxt[j];
        if(c[j+1]==c[i]) j++;
        nxt[i]=j;
    }
    // for(int i=1;i<=len;i++) cout<<nxt[i]<<" ";
    // cout<<endl;
    read(q);

    for(int i=1;i<=q;i++){
        cin>>str[i];
        num[i].first=i;
    }

    sort(num+1,num+1+q,cmp);

    for(int i=1;i<=q;i++) num[i].second=i;

    for(int p=1;p<=q;p++){
        int k=num[p].first;
        // cout<<str[k]<<endl;
        str[k]=' '+str[k];
        int opt=1;
        for(int i=1;i<=min(str[k].size(),str[num[p-1].first].size());i++){
            if(str[k][i]==str[num[p-1].first][i]) opt++;
            else break;
        }
        for(int i=len+opt,j=nxt[len+opt-1];i<len+str[k].size();i++){
            while(j&&SStr(j+1,k)!=SStr(i,k)) j=nxt[j];
            if(SStr(j+1,k)==SStr(i,k)) j++;
            nxt[i]=j;
        }
        for(int i=len+1;i<len+str[k].size();i++) s[num[p].second].push_back(nxt[i]);
    }

    sort(num+1,num+1+q);
    for(int i=1;i<=q;i++){
        for(int j=0;j<s[num[i].second].size();j++) cout<<s[num[i].second][j]<<" ";
        cout<<endl;
    }
}

int main() {
    T=1;
    while(T--) {
        solve();
    }
    return 0;
}