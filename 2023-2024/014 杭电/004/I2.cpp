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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const int ml[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int t;
int n,m;
string str;
vector<string> dd;
int op[50];

void init(){
    for(int i=1;i<=12;i++){
        for(int j=1;j<=ml[i];j++){
            string s=to_string(i/10)+to_string(i%10)+to_string(j/10)+to_string(j%10);
            dd.push_back(s);
            // cout<<s<<endl;
        }
    }
}

vector<string> name(1000010);
vector<vector<int>> nxt(1000010,vector<int>(30,-1)); 
// vector<vector<int>> suf(1000010,vector<int>(30,-1));
vector<int> sum(1000010,0);

int main(){

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    init();
    read(t);
    while(t--){
        read(n),read(m);
        cin>>str;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>name[i];
        for(int i=0;i<=m;i++) sum[i]=0;
        
        for(int i=0;i<=30;i++) op[i]=-1;
        for(int i=0;i<m;i++){
            int k=str[i]-'0';
            if(k>=0&&k<=9) op[k]=i;
            for(int j=0;j<10;j++) nxt[i][j]=op[j];
        }
        // for(int i=0;i<m;i++) cout<<suf[i][9]<<endl;
        for(int i=0;i<366;i++){
            int pos=m;
            for(int j=3;j>=0;j--){
                if(pos==-1||pos==0){pos=-1;break;}
                int k=dd[i][j]-'0';
                pos=nxt[pos-1][k];
            } 
            if(pos!=-1) sum[pos]++;
        }
        for(int i=m-1;i>=0;i--) sum[i]=sum[i]+sum[i+1];

        for(int i=0;i<=30;i++) op[i]=-1;
        for(int i=m-1;i>=0;i--){
            int k=str[i]-'a';
            if(k>=0&&k<=25) op[k]=i;
            for(int j=0;j<26;j++) nxt[i][j]=op[j];
        }
        for(int i=1;i<=n;i++){
            int pos=0;
            for(int j=0;j<name[i].length();j++){
                int k=name[i][j]-'a';
                if(j==0){
                    if(name[i][0]==str[0]) pos=0;
                    else pos=nxt[0][k];
                    continue;
                }
                if(pos==-1) break;
                pos=nxt[pos+1][k];
            }
            if(pos!=-1) ans+=sum[pos];
            // cout<<pos<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}