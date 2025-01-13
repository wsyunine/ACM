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

string name_fac1,name_fac2,name_fac;
vector<string> fac[30];
vector<int> fac_new,tmp;
vector<string> building_class,building_class_ez;
vector<int> data_building_class_short;
map<string,int> cnt,cnt_class;
map<string,double> f;

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

    string fname="Newyork_raw.csv";
    string __fname="Newyork_ver0.3.csv";

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

    int len=fac[1].size(),op_num=0,op_class=0;

    for(int i=0;i<len;i++){
        fac[3][i]=fac[3][i].substr(0,2);
        cout<<fac[3][i]<<endl;
        if(isNum(fac[11][i])) fac_new.push_back(i); 
    }

    len=fac_new.size();

    for(int i=0;i<len;i++){
        int j=fac_new[i];
        if(cnt[fac[2][j]]) fac[2][j]=to_string(cnt[fac[2][j]]);
        else cnt[fac[2][j]]=++op_num,fac[2][j]=to_string(cnt[fac[2][j]]);
    }

    for(int i=0;i<len;i++){
        int j=fac_new[i];
        if(fac[8][j]!="0") fac[8][j]=to_string(2017-stoi(fac[8][j]));
        else fac[8][j]=" -  ";
    }

    for(int i=0;i<len;i++){
        int j=fac_new[i];
        f[fac[10][j]]+=1;
        if(f[fac[10][j]]==1) building_class.push_back(fac[10][j]);
    }
    for(int i=0;i<len;i++){
        if(f[fac[10][fac_new[i]]]/(double)len>=0.001&&(fac[10][fac_new[i]]!="RG")) tmp.push_back(fac_new[i]);
        else data_building_class_short.push_back(fac_new[i]);
    }

    // cout<<data_building_class_short.size()<<endl;

    for(int i=0;i<data_building_class_short.size();i++){
        int ii=data_building_class_short[i],mni=0;
        __int128_t mn=(__int128_t)10000000000000;
        mn=mn*mn;
        for(auto j:tmp){
            // cout<<j<<endl;
            if(mn>cal(ii,j)) mn=cal(ii,j),mni=j;
        }
        // cout<<fac[10][ii]<<endl;
        fac[10][ii]=fac[10][mni];
    }

    for(int i=0;i<len;i++){
        int j=fac_new[i];
        if(cnt_class[fac[10][j]]);
        else cnt_class[fac[10][j]]=1,building_class_ez.push_back(fac[10][j]);
    }

    // name_fac="LOCATATION,BUILDING CLASS CATEGORY,RESIDENTIAL UNITS,COMMERCIAL UNITS,LAND SQUARE FEET,GROSS SQUARE FEET,YEAR BUILT TO NOW,TAX CLASS AT TIME OF SALE,BUILDING CLASS AT TIME OF SALE,SALE PRICE";

    name_fac1="NEIGHBORHOOD";
    name_fac2="RESIDENTIAL UNITS,COMMERCIAL UNITS,LAND SQUARE FEET,GROSS SQUARE FEET,YEAR BUILT TO NOW";

    ofstream outFile(__fname,ios::app);

    for(int i=1;i<=5;i++) outFile<<"BOROUGH"<<to_string(i)<<',';

    outFile<<name_fac1<<',';

    for(int i=1;i<=49;i++) outFile<<"BUILDING CLASS CATEGORY"<<to_string(i)<<',';

    outFile<<name_fac2<<',';

    for(int i=1;i<=4;i++) outFile<<"TAX CLASS"<<to_string(i)<<',';

    for(int i=0;i<building_class_ez.size()-1;i++) outFile<<building_class_ez[i]<<',';
    outFile<<building_class_ez[building_class_ez.size()-1]<<','<<"SALE PRICE"<<endl;

    for(int i=0;i<len;i++){
        int k=fac_new[i];
        for(int j=1;j<=5;j++){
            if(to_string(j)==fac[1][k]) outFile<<"1"<<',';
            else outFile<<"0"<<',';
        }
        for(int j=2;j<=2;j++) outFile<<fac[j][k]<<',';

        for(int j=1;j<=49;j++){
            if(stoi(fac[3][k])==j) outFile<<"1"<<',';
            else outFile<<"0"<<',';
        }

        for(int j=4;j<=8;j++) outFile<<fac[j][k]<<',';

        for(int j=1;j<=4;j++){
            if(fac[9][k]==to_string(j)) outFile<<"1"<<',';
            else outFile<<"0"<<',';
        }

        for(int j=0;j<building_class_ez.size();j++){
            if(building_class_ez[j]==fac[10][k]) outFile<<"1"<<',';
            else outFile<<"0"<<',';
        }
        outFile<<fac[11][k]<<endl;
    }

    outFile.close();

    return 0;
}
/*

New York

note:
ver0.1
1. 社区名称由字符串类型转换为离散数值类型
2. 建筑类型只保留前缀编码，数值型，无前缀0
3. 售价确失数据删除
4. 建成年份转换为距售出年份的年数（售出年份统一按2017计算）
5. 只保留11个影响因子

ver0.21
6. 保留行政区编号并转换成one-hot变量
7. 建筑等级少量剔除并转换为one-hot变量

ver0.3
8. 建筑等级RG拆掉
9. 建筑类别、售出时税种转换成one-hot 

solved problem:
1. 售出时建筑等级需不需要处理，开头字母对数据是否有较大影响
2. 剔除售价缺失数据后发现售价有错误数据，需要进一步剔除
3. 按社区名称分类已经可以保证不受行政区编号影响，两因子合并无意义
   要留行政区编号（5类数据多拟合效果较差操作简单）还是留社区名称（254类数据少拟合效果好操作复杂）
   建议留社区名称，但是需要学习实际操作方法

*/

