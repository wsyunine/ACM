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

int n, m;
string a, b;
int t;
int mapp[10010];
int res = 0, sum = 0;

int main()
{
    read(t);
    while(t--) {
        read(n), read(m);

        res = 0;
        cin >> a >> b;
        if(n < m) {
            swap(a, b);
            swap(n, m);
        }

        for(int i = 'a'; i <= 'z'; i++) mapp[i] = 0;

        for(auto i : a) {
            mapp[i]++;
        }

        for(auto i : b) {
            if(mapp[i]) {
                mapp[i]--;
            }
            else {
                res++;
            }
        }

        sum = 0;
        for(int i = 'a'; i <= 'z'; i++) {
            sum += mapp[i];
        }

        int op = (sum - res) / 2;

        for(int i = 'a'; i <= 'z'; i++) {
            while(mapp[i] >= 2 && op) op--, mapp[i] -= 2;
            if(!op) break;
        }

        cout << res + op << endl;
    }

    return 0;
}
