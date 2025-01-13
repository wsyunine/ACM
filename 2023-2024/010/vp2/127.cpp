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

//typedef __int128 LLL;
typedef long long LL;
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

// void print(__int128 value) {
//     if (value < 0) {
//         value = -value;
//         putchar('-');
//     }
//     if (value > 9) print(value / 10);
//     putchar(value % 10 + '0');
// }


int main()
{
    //LL x;
    //read(x);
    //LL n = (LL)x;
    LL n;
    cin >> n;
    LL sum = 0;
    for (LL i = 5; i <= n; i *= 5)
    {
        LL cnt = n / i;
        LL fst = i - 1, lst = fst + cnt * i;
        LL res = n * cnt - (fst + lst) * cnt / 2;
        sum += res;
    }
    cout << sum << endl;
    //print(sum);
    return 0;
}