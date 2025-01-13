#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<fstream>
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
#include<cstdint>
using namespace std;
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

string name_fac;
vector<string> fac[30];
vector<string> sp1,sp2;
map<string,int> mapp1,mapp2;

bool isNum(string str){
    stringstream sin(str);
    double d;
    char c;
    if(!(sin >> d)){
        return false;
    }
    if (sin >> c){
        return false;
    }
    return true;
}

__int128_t abst(__int128_t a){
    return a>=0?a:-a;
}

__int128_t cal(int a,int b){
    __int128_t ans=abst((__int128_t)(stol(fac[3][a]))-(__int128_t)(stol(fac[3][b])))*abst((__int128_t)(stol(fac[3][a]))-(__int128_t)(stol(fac[3][b])))+abst((__int128_t)(stol(fac[4][a]))-(__int128_t)(stol(fac[4][b])))*abst((__int128_t)(stol(fac[4][a]))-(__int128_t)(stol(fac[4][b])))+abst((__int128_t)(stol(fac[5][a]))-(__int128_t)(stol(fac[5][b])))*abst((__int128_t)(stol(fac[5][a]))-(__int128_t)(stol(fac[5][b])))+abst((__int128_t)(stol(fac[11][a]))-(__int128_t)(stol(fac[11][b])))*abst((__int128_t)(stol(fac[11][a]))-(__int128_t)(stol(fac[11][b])));
    // cout<<ans<<endl;
    return ans;
}

int main(){

    string fname="Bangalore_raw.csv";
    string __fname="Bangalore_ver0.1.csv";

    ifstream csv_data(fname,ios::in);

    if(!csv_data.is_open()){
        cout<<"Error: opening file fail"<<endl;
        exit(1);
    }else{
        string line;
        string word;
        getline(csv_data,line);

        name_fac=line;

        istringstream sin;

        while(getline(csv_data,line)){

            int j=1;

            sin.clear();
            sin.str(line);
            while(getline(sin,word,',')) fac[j].push_back(word),j++;
        }
        csv_data.close();
    }

    int len=fac[1].size(),op1=0,op2=0;

    for(int i=0;i<len;i++){
        if(fac[1][i]=="Built-up  Area") fac[1][i]="1";
        if(fac[1][i]=="Carpet  Area") fac[1][i]="2";
        if(fac[1][i]=="Plot  Area") fac[1][i]="3";
        if(fac[1][i]=="Super built-up  Area") fac[1][i]="4";
    }

    for(int i=0;i<len;i++){
        if(mapp1[fac[2][i]]);
        else mapp1[fac[2][i]]=++op1,sp1.push_back(fac[2][i]);
    }

    for(int i=0;i<len;i++){
        if(mapp2[fac[3][i]]);
        else mapp2[fac[3][i]]=++op1,sp2.push_back(fac[3][i]);
    }

    // do something...

    name_fac="total_sqft,bath,balcony,price";

    ofstream outFile(__fname,ios::app);

    outFile<<"Built-up  Area,Carpet  Area,Plot  Area,Super built-up  Area,";
    for(auto i:sp1) outFile<<i<<',';
    for(auto i:sp2) outFile<<i<<',';
    outFile<<name_fac<<endl;

    for(int i=0;i<len;i++){
        for(int j=1;j<=4;j++){
            if(j==stoi(fac[1][i])) outFile<<'1'<<',';
            else outFile<<'0'<<',';
        }
        for(auto j:sp1){
            if(j==fac[2][i]) outFile<<'1'<<',';
            else outFile<<'0'<<',';
        }
        for(auto j:sp2){
            if(j==fac[3][i]) outFile<<'1'<<',';
            else outFile<<'0'<<',';
        }
        for(int j=4;j<=6;j++) outFile<<fac[j][i]<<',';
        outFile<<fac[7][i]<<endl;
    }

    outFile.close();

    return 0;
}