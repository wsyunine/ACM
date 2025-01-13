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
map<string,int> ocean_p;
vector<string> ocean_p_c; 

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

    string fname="California_raw.csv";
    string __fname="California_ver0.1.csv";

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

    int len=fac[1].size(),op_ocean=0;

    for(int i=0;i<=len-1;i++){
        if(ocean_p[fac[10][i]]) fac[10][i]=to_string(ocean_p[fac[10][i]]);
        else ocean_p[fac[10][i]]=++op_ocean,ocean_p_c.push_back(fac[10][i]),fac[10][i]=to_string(ocean_p[fac[10][i]]);
    }

    // do something...

    name_fac="longitude,latitude,housing_median_age,total_rooms,total_bedrooms,population,households,median_income,median_house_value";

    ofstream outFile(__fname,ios::app);

    outFile<<name_fac<<',';
    for(int i=0;i<op_ocean-1;i++) outFile<<ocean_p_c[i]<<',';
    outFile<<ocean_p_c[ocean_p_c.size()-1]<<endl;

    for(int i=0;i<fac[1].size();i++){
        for(int j=1;j<=9;j++){
            outFile<<fac[j][i]<<',';
        }
        for(int j=1;j<=op_ocean-1;j++){
            if(j==stoi(fac[10][i])) outFile<<'1'<<',';
            else outFile<<'0'<<',';
        }
        if(op_ocean==stoi(fac[10][i])) outFile<<'1'<<endl;
        else outFile<<'0'<<endl;
    }

    outFile.close();

    return 0;
}
/*

California

note:
1. 离海距离分为5类并转换为one-hot向量
2. 

problem:

*/

