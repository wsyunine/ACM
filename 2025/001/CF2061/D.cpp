
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
#include <unordered_map>
#include <vector>
using namespace std;
#define N 500010
#define ll long long
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

int T;
int n;
int m;
ll a[N], b[N];
ll sa, sb;
unordered_map<int, int> mapp;

bool shakes(int x)
{
    if(x == 1) {
        if(!mapp[x]) return 0;
        mapp[x]--;
        return 1;
    }
    if(!mapp[x]) {
        return (shakes(x / 2) & shakes(x - x / 2));
    }
    else
        mapp[x]--;
    return 1;
}

void solve()
{
    sa = sb = 0;
    read(n), read(m);
    mapp.clear();
    for(int i = 1; i <= n; i++) read(a[i]), sa += a[i], mapp[a[i]]++;
    for(int i = 1; i <= m; i++) read(b[i]), sb += b[i];

    // cout << n << " " << m << endl;
    // for(int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << endl;
    // for(int i = 1; i <= m; i++) cout << b[i] << " ";
    // cout << endl;

    if(sa != sb) {
        cout << "No" << endl;
        return;
    }

    for(int i = 1; i <= m; i++) {
        if(shakes(b[i])) {
        }
        else {
            cout << "No" << endl;
            return;
        }
    }

    for(auto i : mapp) {
        if(i.second != 0) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    /*
    int op1 = 1, op2 = 1;
    while(op1 <= n && op2 <= m) {
        while(op1 <= n && op2 <= m && a[op1] != b[op2]) {
            if(a[op1] < b[op2]) {
                op1++;
                if(a[op1] - a[op1 - 1] > 1 || op1 > n) {
                    cout << "No" << endl;
                    return;
                }
                a[op1] += a[op1 - 1];
            }
            else {
                cout << "No" << endl;
                return;
            }
        }
        if(a[op1] == b[op2]) {
            op1++;
            op2++;
        }
    }

    if(op1 > n && op2 > m) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    */
}

int main()
{
    read(T);
    while(T--) {
        solve();
    }

    return 0;
}
