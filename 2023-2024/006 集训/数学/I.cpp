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
int n,k;
int mapp[10][110];

int main(){

    read(t);
    mapp[1][1]=1;
    mapp[2][2]=mapp[2][12]=1;
    mapp[3][3]=mapp[3][13]=mapp[3][23]=1;
    mapp[4][4]=mapp[4][14]=mapp[4][24]=mapp[4][34]=1;
    mapp[5][5]=mapp[5][15]=mapp[5][25]=mapp[5][35]=mapp[5][45]=1;
    mapp[6][6]=mapp[6][16]=mapp[6][26]=mapp[6][36]=mapp[6][46]=mapp[6][56]=1;
    mapp[7][7]=mapp[7][17]=mapp[7][27]=mapp[7][37]=mapp[7][47]=mapp[7][57]=mapp[7][67]=1;
    mapp[8][8]=mapp[8][18]=mapp[8][28]=mapp[8][38]=mapp[8][48]=mapp[8][58]=mapp[8][68]=mapp[8][78]=1;
    mapp[9][9]=mapp[9][19]=mapp[9][29]=mapp[9][39]=mapp[9][49]=mapp[9][59]=mapp[9][69]=mapp[9][79]=mapp[9][89]=1;
    
    for(int i=1;i<=9;i++){
        for(int j=1;j<=i*10;j++){
            for(int k=1;k<j;k++){
                mapp[i][j]=mapp[i][j]|(mapp[i][k]&mapp[i][j-k]);
            }
        }
    }

    while(t--){
        read(n),read(k);
        for(int i=1;i<=n;i++){
            int opt;
            read(opt);
            if(opt>=10*k) printf("YES\n");
            else if(mapp[k][opt]) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}