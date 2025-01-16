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
#define N 50010
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

long long dp[101][10][10];
int n;

int main()
{
    memset(dp, 0, sizeof dp);
    dp[1][1][1] = dp[1][2][2] = dp[1][3][3] = 1;
    for(int i = 2; i <= 50; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                for(int p = 1; p <= 3; p++) {
                    if(p != k) dp[i][j][k] += dp[i - 1][j][p];
                }
            }
        }
    }

    dp[1][0][0] = 3;
    for(int i = 2; i <= 50; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(j != k) dp[i][0][0] += dp[i][j][k];
            }
        }
    }

    while(cin >> n) {
        cout << dp[n][0][0] << endl;
    }

    return 0;
}
