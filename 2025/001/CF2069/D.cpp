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

int T,n;
string str;
int lft[N][30],rgt[N][30];
int sum[N][30];

void solve() {
    cin>>str;
    str=' '+str;
    int l=-1,r=-1,mxl=0,mnr=str.size()-1;
    n=str.size()-1;
    vector<int> c(300);
    for(int i='a';i<='z';i++) c[i]=0;
    for(int i=1;i<=n;i++){
        for(int j='a';j<='z';j++){
            lft[i][j-'a']=c[j];
        }
        c[str[i]]=i;
    }
    for(int i='a';i<='z';i++) c[i]=0;
    for(int i=n;i>=1;i--){
        for(int j='a';j<='z';j++){
            rgt[i][j-'a']=c[j];
        }
        c[str[i]]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j='a';j<='z';j++){
            sum[i][j-'a']=sum[i-1][j-'a']+(str[i]==j);
        }
    }

    for(int i='a';i<='z';i++) c[i]=0;
    for(int i=1;i<=n/2;i++){
        if(n+1-i<=mxl) break;
        if(l==-1&&str[i]==str[n+1-i]) continue;
        else if(l==-1&&str[i]!=str[n+1-i]){
            l=i;
            c[str[n+1-i]]++;
            mxl=max(mxl,rgt[i][str[n+1-i]-'a']);
        }else{
            if(i>mxl&&str[i]==str[n+1-i]) continue;
            else if(i<=mxl&&str[i]==str[n+1-i]){
                c[str[n+1-i]]++;
                while(sum[mxl][str[n+1-i]-'a']-sum[l-1][str[n+1-i]-'a']<c[str[n+1-i]]){
                    mxl=min(rgt[mxl][str[n+1-i]-'a'],n+1-i);
                    if(mxl>=n+1-i) c[str[n+1-i]]--;
                }
                continue;
            }else if(i>mxl&&str[i]!=str[n+1-i]){
                for(int p=mxl+1;p<i;p++) c[str[n+1-p]]++;
                mxl=i;
            }
            c[str[n+1-i]]++;
            while(sum[mxl][str[n+1-i]-'a']-sum[l-1][str[n+1-i]-'a']<c[str[n+1-i]]){
                mxl=min(rgt[mxl][str[n+1-i]-'a'],n+1-i);
                if(mxl>=n+1-i) c[str[n+1-i]]--;
            }
        }
    }
    // cerr<<l<<" "<<mxl<<endl;

    for(int i='a';i<='z';i++) c[i]=0;
    for(int i=1;i<=n/2;i++){
        if(i>=mnr) break;
        if(r==-1&&str[i]==str[n+1-i]) continue;
        else if(r==-1&&str[i]!=str[n+1-i]){
            r=n+1-i;
            c[str[i]]++;
            mnr=min(mnr,lft[n+1-i][str[i]-'a']);
        }else{
            if(n+1-i<mnr&&str[i]==str[n+1-i]) continue;
            else if(n+1-i>=mnr&&str[i]==str[n+1-i]){
                c[str[i]]++;
                while(sum[r][str[i]-'a']-sum[mnr-1][str[i]-'a']<c[str[i]]){
                    mnr=lft[mnr][str[i]-'a'];
                    if(mnr<=i) c[str[i]]--;
                }
                continue;
            }else if(n+1-i<mnr&&str[i]!=str[n+1-i]){
                for(int p=n+1-i+1;p<mnr;p++) c[str[n+1-p]]++;
                mnr=n+1-i;
            }
            c[str[i]]++;
            while(sum[r][str[i]-'a']-sum[mnr-1][str[i]-'a']<c[str[i]]){
                mnr=lft[mnr][str[i]-'a'];
                if(mnr<=i) c[str[i]]--;
            }
        }
        // cerr<<i<<" "<<mnr<<endl;
    }
    // cout<<r<<" "<<mnr<<endl;
    if(l==-1) cout<<0<<endl;
    else cout<<min(mxl-l+1,r-mnr+1)<<endl;

}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}