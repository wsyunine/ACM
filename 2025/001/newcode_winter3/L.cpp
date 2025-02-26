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

int n;
int pp, ee;
int mapp[9][9];
vector<int> s, s1;

int main()
{
    read(n);
    printf("Yes\n");

    pp = (n + 1) * (n + 2) / 2;
    ee = 3 * n * (n + 1) / 2;

    int tmp = 0;
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= i; j++) {
            mapp[i][j] = ++tmp;
        }
    }

    s.push_back(1);
    for(int i = 1; i <= n; i++) {
        int op = 1;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == mapp[i][op]) {
                s1.push_back(mapp[i][op]);
                s1.push_back(mapp[i + 1][op]);
                s1.push_back(mapp[i + 1][op + 1]);
                s1.push_back(mapp[i][op]);
                op++;
            }
            else
                s1.push_back(s[j]);
        }
        s = s1;
        s1.clear();
    }

    for(auto i : s) printf("%d ", i);
    cout << endl;

    return 0;
}
