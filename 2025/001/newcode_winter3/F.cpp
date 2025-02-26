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

int t;
int n, a, b, c;

int main()
{
    read(t);
    while(t--) {
        read(n), read(a), read(b), read(c);

        int idea = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; i + j <= n; j++) {
                for(int k = 0; i + j + k <= n; k++) {
                    for(int p = 0; i + j + k + p <= n; p++) {
                        for(int q = 0; i + j + k + p + q <= n; q++) {
                            if(i + j + k == a && k + p + q == b &&
                               q + (n - i - j - k - q - p) + i == c)
                                idea = 1;
                        }
                    }
                }
            }
        }

        if(idea)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
