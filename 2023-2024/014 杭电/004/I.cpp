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

int n;
int t;
int m;
string str;
vector<string> dd;

void init(){
    for(int i=1;i<=12;i++){
        for(int j=1;j<=ml[i];j++){
            string s=to_string(i/10)+to_string(i%10)+to_string(j/10)+to_string(j%10);
            dd.push_back(s);
            // cout<<s<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    init();
    // cout<<dd.size()<<endl;
    read(t);
    while(t--){
        read(n);read(m);
        vector<string> name(n+10);
        vector<int> ch[1000],pos(n+10,0),ed(n+10,0);
        vector<int> dp(m+10,0),chh[1000],poss(400,3);
        long long ans=0;
        cin>>str;
        for(int i=1;i<=n;i++){
            cin>>name[i];
            int ip=name[i][0];
            ch[ip].push_back(i),pos[i]=0;
        }
        for(int c=0;c<m;c++){
            if(str[c]<'a'||str[c]>'z') continue;
            vector<int> op;
            int sop=str[c];
            op=ch[sop];
            ch[sop].clear();
            for(int i=0;i<op.size();i++){
                pos[op[i]]++;
                if(pos[op[i]]<name[op[i]].length()) ch[(int)name[op[i]][pos[op[i]]]].push_back(op[i]);
                else ed[op[i]]=c;
            }
        }
        // for(int i=1;i<=n;i++) cout<<ed[i]<<endl;
        //
        for(int i=0;i<dd.size();i++){
            int ip=dd[i][3];
            chh[ip].push_back(i);
        }
        dp[m]=0;
        for(int i=m-1;i>=0;i--){
            if(str[i]<'0'||str[i]>'9'){
                dp[i]=dp[i+1];
                continue;
            }
            vector<int> op;
            int sop=str[i];
            op=chh[sop];
            int ee=0;
            chh[sop].clear();
            cout<<op.size()<<endl;
            for(int j=0;j<op.size();j++){
                poss[op[j]]--;
                if(poss[op[j]]>=0) chh[(int)dd[op[j]][poss[op[j]]]].push_back(op[j]);
                else ee++;
            }
            dp[i]=dp[i+1]+ee;
        }

        for(int i=1;i<=n;i++){
            if(pos[i]>=name[i].length()) ans+=dp[ed[i]];
        }
        cout<<ans<<endl;
        name.clear(),pos.clear(),ed.clear(),dp.clear(),poss.clear();
    }

    return 0;
}
/*

1 20  
l0l2l0l1l22l112l2332
l
ll

*/