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

int n;

//data init
map<string,int> mapp;
int cnt=4;
int o[110][110];
map<string,pair<int,int>> lx[110];
pair<int,int> bb[110];
string ed;

//memory
map<string,int> my;
int sum=0,ss=0;
pair<int,int> sta[110];

int main(){

    mapp["byte"]=1;bb[1]=make_pair(1,1);
    mapp["short"]=2;bb[2]=make_pair(2,2);
    mapp["int"]=3;bb[3]=make_pair(4,4);
    mapp["long"]=4;bb[4]=make_pair(8,8);

    read(n);
    while(n--){
        int opt;
        string s1,s2;
        int m;
        read(opt);

        if(opt==1){
            int mx=0;
            cin>>s1;
            read(m);
            mapp[s1]=++cnt;
            for(int i=1;i<=m;i++){
                string l,name;
                cin>>l>>name;
                lx[cnt][name].first=mapp[l];
                lx[cnt][name].second=i;
                o[cnt][i]=mapp[l];
                mx=max(mx,bb[mapp[l]].first);
            }
            bb[cnt].first=mx*m;
            bb[cnt].second=mx;
            cout<<mx*m<<" "<<mx<<endl;
        }else if(opt==2){
            cin>>s1>>s2;
            ed=s2;
            my[s2]=++sum;
            sta[sum]=make_pair(mapp[s1],ss);
            ss+=bb[mapp[s1]].first;
            cout<<sta[sum].second<<endl;
        }else if(opt==3){
            cin>>s1;
            int len=s1.size(),i,pos,poslx;
            string s;
            for(i=0;i<len;i++){
                if(s1[i]=='.') break;
                else s.push_back(s1[i]);
            }
            pos=sta[my[s]].second;
            poslx=sta[my[s]].first;
            if(i>=len){cout<<pos<<endl;continue;}
            s.clear();i++;
            while(i<len){
                if(s1[i]=='.'){
                    pos+=(lx[poslx][s].second-1)*bb[poslx].second;
                    poslx=lx[poslx][s].first;
                    s.clear();
                }else{
                    s.push_back(s1[i]);
                }
                i++;
            }
            pos+=(lx[poslx][s].second-1)*bb[poslx].second;
            cout<<pos<<endl;
        }else{
            read(m);
            if(m>=ss){cout<<"ERR"<<endl;continue;}
            int pos=-1,poslx;
            vector<string> ans;
            for(auto i:my){
                if(sta[i.second].second>m){ans.push_back(i.first),pos=i.second-1;poslx=sta[i.second].first;break;}
            }
            if(pos==-1) pos=sta[sum].second,poslx=sta[sum].first,ans.push_back(ed);
            while(poslx>4){
                int bc=bb[poslx].second;
                for(auto i:lx[poslx]){
                    if(pos+bc-1>=m){poslx=i.second.first,ans.push_back(i.first);break;}
                    pos+=bc;
                }
                // int tmp=((m-pos)/bb[poslx].second)+1;
                // pos+=(bb[poslx].second*(tmp-1));
                // poslx=o[poslx][tmp];
            }
            if(pos+bb[poslx].first-1<m) cout<<"ERR"<<endl;
            else{
                int lop=ans.size();
                for(int i=0;i<lop-1;i++){
                    cout<<ans[i]<<".";
                }
                cout<<ans[lop-1]<<endl;
            }
        }
    }

    return 0;
}