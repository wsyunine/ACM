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
int spe,sta,po,gut,wis,ski;
int spe0,sta0,po0,gut0,wis0,spe1,sta1,po1,gut1,wis1;
int fri[7],dri[7],tra[7],spe2[7],sta2[7],po2[7],gut2[7],wis2[7],spe3[7],sta3[7],po3[7],gut3[7],wis3[7];
int lvs[5];
double base[6][5][7]={{{},{},{},{},{}},{{0,10,0,5,0,0,2},{0,0,9,0,4,0,2},{0,0,5,8,0,0,2},{0,4,0,4,8,0,2},{0,2,0,0,0,9,4}},{{0,11,0,5,0,0,2},{0,0,10,0,4,0,2},{0,0,5,9,0,0,2},{0,4,0,4,9,0,2},{0,2,0,0,0,10,4}},{{0,12,0,5,0,0,2},{0,0,11,0,4,0,2},{0,0,6,10,0,0,2},{0,4,0,4,10,0,2},{0,3,0,0,0,11,4}},{{0,13,0,5,0,0,2},{0,0,12,0,4,0,2},{0,0,6,11,0,0,2},{0,4,0,4,11,0,2},{0,3,0,0,0,12,4}},{{0,14,0,5,0,0,2},{0,0,13,0,4,0,2},{0,0,7,12,0,0,2},{0,5,0,5,12,0,2},{0,4,0,0,0,13,4}}};
int sum,wei,drii,typ,S,lv,map1[7],map2[7];
double coef[5]={-0.2,-0.1,0,0.1,0.2};

int main(){

    read(spe0),read(sta0),read(po0),read(gut0),read(wis0);
    read(spe1),read(sta1),read(po1),read(gut1),read(wis1);
    for(int i=1;i<=6;i++){
        read(fri[i]),read(dri[i]),read(tra[i]);
        read(spe2[i]),read(sta2[i]),read(po2[i]),read(gut2[i]),read(wis2[i]);
        read(spe3[i]),read(sta3[i]),read(po3[i]),read(gut3[i]),read(wis3[i]);
    }
    ski=120;spe=spe0;sta=sta0;po=po0;gut=gut0;wis=wis0;
    for(int i=1;i<=6;i++) spe+=spe2[i];
    for(int i=1;i<=6;i++) sta+=sta2[i];
    for(int i=1;i<=6;i++) po+=po2[i];
    for(int i=1;i<=6;i++) gut+=gut2[i];
    for(int i=1;i<=6;i++) wis+=wis2[i];
    spe=min(1200,spe);sta=min(1200,sta);po=min(1200,po);gut=min(1200,gut);wis=min(1200,wis);
    // cout<<spe<<" "<<sta<<" "<<po<<" "<<gut<<" "<<wis<<" "<<ski<<endl;
    read(n);
    while(n--){
        for(int i=1;i<=6;i++) map1[i]=0,map2[i]=0;
        read(sum),read(wei),read(drii),read(typ),read(S);
        if(sum) lv=5;
        else lv=min(lvs[typ]/4+1,5),lvs[typ]++;;
        for(int i=1,j,k;i<=S;i++){
            read(j),read(k);
            map1[j]=1;
            if(k) map2[j]=1;
        }
        int dx=0;double ddx=0;
        double px=0,ff=1,pt=0,pd=0;
        for(int i=1;i<=6;i++){
            if(map1[i]) px+=spe3[i],pt+=tra[i],pd+=dri[i];
            if(map2[i]) ff=ff*(1.0+0.01*(double)fri[i]);
        }
        ddx=(base[lv][typ][1]+px)*ff*(1.0+0.01*pt)*(1.0+coef[drii]*(1.0+0.01*pd))*(1+0.01*(double)spe1)*(1+0.05*(double)S);
        // cout<<spe3[1]<<spe3[2]<<spe3[3]<<spe3[4]<<spe3[5]<<endl;
        dx=ddx;
        if(!wei) spe+=dx;

        dx=0;ddx=0;px=0;
        for(int i=1;i<=6;i++){
            if(map1[i]) px+=sta3[i];
        }
        ddx=(base[lv][typ][2]+px)*ff*(1.0+0.01*pt)*(1.0+coef[drii]*(1.0+0.01*pd))*(1+0.01*(double)sta1)*(1+0.05*(double)S);
        // cout<<ddx<<endl;
        dx=ddx;
        sta+=dx;

        dx=0;ddx=0;px=0;
        for(int i=1;i<=6;i++){
            if(map1[i]) px+=po3[i];
        }
        ddx=(base[lv][typ][3]+px)*ff*(1.0+0.01*pt)*(1.0+coef[drii]*(1.0+0.01*pd))*(1+0.01*(double)po1)*(1+0.05*(double)S);
        // cout<<ddx<<endl;
        dx=ddx;
        po+=dx;

        dx=0;ddx=0;px=0;
        for(int i=1;i<=6;i++){
            if(map1[i]) px+=gut3[i];
        }
        ddx=(base[lv][typ][4]+px)*ff*(1.0+0.01*pt)*(1.0+coef[drii]*(1.0+0.01*pd))*(1+0.01*(double)gut1)*(1+0.05*(double)S);
        // cout<<ddx<<endl;
        dx=ddx;
        gut+=dx;

        dx=0;ddx=0;px=0;
        for(int i=1;i<=6;i++){
            if(map1[i]) px+=wis3[i];
        }
        ddx=(base[lv][typ][5]+px)*ff*(1.0+0.01*pt)*(1.0+coef[drii]*(1.0+0.01*pd))*(1+0.01*(double)wis1)*(1+0.05*(double)S);
        // cout<<ddx<<endl;
        dx=ddx;
        wis+=dx;

        dx=0;ddx=0;
        ddx=base[lv][typ][6]*ff*(1.0+0.01*pt)*(1.0+coef[drii]*(1.0+0.01*pd))*(1+0.05*(double)S);
        // cout<<ddx<<endl;
        dx=ddx;
        ski+=dx;

        spe=min(1200,spe);sta=min(1200,sta);po=min(1200,po);gut=min(1200,gut);wis=min(1200,wis);

        cout<<spe<<" "<<sta<<" "<<po<<" "<<gut<<" "<<wis<<" "<<ski<<endl;
    }

    return 0;
}

/*

71 117 70 102 90 0 10 0 20 0
25 30 15 0 0 0 0 0 0 1 0 0 0
30 30 15 0 0 0 0 30 0 0 0 0 1
25 0 15 0 0 0 0 0 0 0 0 0 2
30 30 10 0 0 20 0 0 0 0 1 0 0
30 30 0 0 0 0 20 0 1 0 1 0 0
30 0 10 0 0 0 0 0 0 0 0 1 0

9
0 1 0 0 1 5 0
0 0 1 0 4 1 1 2 0 3 0 4 0
0 1 2 0 3 1 0 3 0 6 0
0 0 3 0 5 1 1 2 1 3 1 4 1 5 1
0 1 4 0 3 2 1 4 0 6 1
1 0 3 1 0
1 1 4 2 1 3 1
1 0 3 3 3 4 1 5 0 6 1
1 1 4 4 1 4 0

*/