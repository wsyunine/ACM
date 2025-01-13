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

int t;
string a,b,ans;

int main(){

    read(t);
    for(int tmp=1;tmp<=t;tmp++){
        cin>>a>>b;
        ans=a;
        string sa,sb;
        int len=a.size(),slen,cnta=0,cntb=0;
        vector<int> cc;

        for(int i=0;i<len;i++){
            if(a[i]!=b[i]) sb.push_back(b[i]),sa.push_back(a[i]);
            else cc.push_back(i);
        }

        slen=sa.size();
        int lc=cc.size();
        int ed;
        // cout<<slen<<endl;

        if(slen==1){
            ans[0]=(sa[0]=='a'&&sb[0]=='b')||(sa[0]=='b'&&sb[0]=='a')?'c':((sa[0]=='a'||sb[0]=='a')?'b':'a');
        }else{
            for(int i=0;i+cnta+cntb<=slen-1;i++){
                ans[i]='a';   
                if(sa[i]=='a'&&sb[i]!='a'){
                    if(i+cnta+cntb+1>slen-1){ed=i-1;break;}
                    if(cnta) cnta--;
                    else cntb++;
                }else if(sa[i]!='a'&&sb[i]=='a'){
                    if(i+cnta+cntb+1>slen-1){ed=i-1;break;}
                    if(cntb) cntb--;
                    else cnta++;
                }
                ed=i;
            }

            // cout<<slen<<endl;
            
            for(int i=ed+1;i<slen;i++){
                if(sa[i]!='a'&&sb[i]!='a'&&i+cnta+cntb+1==slen){ans[i]='a';continue;}
                // cout<<i<<" "<<cnta<<" "<<cntb<<endl;
                if(cnta==0&&cntb==0) ans[i]=(sa[i]=='a'&&sb[i]=='b')||(sa[i]=='b'&&sb[i]=='a')?'c':((sa[i]=='a'||sb[i]=='a')?'b':'a');
                else if(sa[i]<sb[i]&&cnta>0){
                    ans[i]=sa[i],cnta--;
                    if(i+cnta+cntb+2==slen){
                        char op=(sa[i]=='a'&&sb[i]=='b')||(sa[i]=='b'&&sb[i]=='a')?'c':((sa[i]=='a'||sb[i]=='a')?'b':'a');
                        if(op<ans[i]){
                            ans[i]=op;
                            cnta++;
                        }
                    }
                }
                else if(sa[i]<sb[i]&&cnta==0){
                    ans[i]=sb[i],cntb--;
                    if(i+cnta+cntb+2==slen){
                        char op=(sa[i]=='a'&&sb[i]=='b')||(sa[i]=='b'&&sb[i]=='a')?'c':((sa[i]=='a'||sb[i]=='a')?'b':'a');
                        if(op<ans[i]){
                            ans[i]=op;
                            cntb++;
                        }
                    }
                }
                else if(sb[i]<sa[i]&&cntb>0){
                    ans[i]=sb[i],cntb--;
                    if(i+cnta+cntb+2==slen){
                        char op=(sa[i]=='a'&&sb[i]=='b')||(sa[i]=='b'&&sb[i]=='a')?'c':((sa[i]=='a'||sb[i]=='a')?'b':'a');
                        if(op<ans[i]){
                            ans[i]=op;
                            cntb++;
                        }
                    }
                }
                else{
                    ans[i]=sa[i],cnta--;
                    if(i+cnta+cntb+2==slen){
                        char op=(sa[i]=='a'&&sb[i]=='b')||(sa[i]=='b'&&sb[i]=='a')?'c':((sa[i]=='a'||sb[i]=='a')?'b':'a');
                        if(op<ans[i]){
                            ans[i]=op;
                            cnta++;
                        }
                    }
                }
                // cout<<i<<" "<<cnta<<" "<<cntb<<endl;
            }

            // cout<<ans<<endl;
        }

        

        cout<<"Case "<<tmp<<": ";
        int i=0,j=0,k=0;
        while(k<lc&&j==cc[k]&&j<len) cout<<'a',j++,k++;
        for(;i<slen;i++,j++){
            while(k<lc&&j==cc[k]&&j<len) cout<<'a',j++,k++;
            cout<<ans[i];
        }
        while(k<lc&&j==cc[k]&&j<len) cout<<'a',j++,k++;
        cout<<endl;
    }

    return 0;
}