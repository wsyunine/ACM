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
#define N 1 << 22
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}


int n, m, k, q;
int zz;
int p[100];
int pz[100];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= 3 * n / m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            p[i] |= (1 << (x - 1));
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        zz |= (1 << (x - 1));
    }
    cin >> q;
    for (int i = 1; i <= 3 * n / m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            pz[i] += ((zz >> j) & (p[i] >> j));
        }
    }


    for (int i = 1; i <= )
}