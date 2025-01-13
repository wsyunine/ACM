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
vector<string> s1;
map<string,int> cnt1;

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

    string fname="Kualalumpur_raw.csv";
    string __fname="Kualalumpur_ver0.1.csv";

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

    int len=fac[1].size(),op1=0;

    for(int i=0;i<=len-1;i++){
        cnt1[fac[8][i]]
    }

    // do something...

    

    name_fac="Price,Rooms,Bathrooms,Car Parks,Property Type,Size,Furnishing";

    ofstream outFile(__fname,ios::app);

    for(int i=0;i<s1.size();i++) outFile<<s1[i]<<',';
    outFile<<name_fac<<endl;

    for(int i=1;i<=len;i++){
        
    }

    outFile.close();

    return 0;
}

