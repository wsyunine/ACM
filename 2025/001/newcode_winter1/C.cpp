#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <thread>
#include <vector>
using namespace std;
#define N 500010
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int n, T;
int mapp[110][110];
vector<int> s1, s2, s3, s4;

int main()
{
    read(T);
    while(T--) {
        s1.clear();
        s2.clear();
        s3.clear();
        s4.clear();
        read(n);
        for(int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < n; j++) {
                mapp[i][j + 1] = s[j] == '0' ? 0 : 1;
            }
        }

        for(int i = 1; i <= n / 2; i++) {
            for(int j = 1; j <= n / 2; j++) {
            }
        }

        printf("%zu\n", s1.size());
        for(int i = 0; i < s1.size(); i++) {
            printf("%d %d %d %d\n", s1[i], s2[i], s3[i], s4[i]);
        }
    }

    return 0;
}
