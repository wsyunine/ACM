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
#define int long long
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
int a[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(T);
    while(T--) {
        read(n);
        multiset<int> s;
        for(int i = 1; i <= n; i++) {
            read(a[i]);
            if(a[i] > 0) {
                if(a[i] / 3) s.insert(a[i] / 3 * 3);
                if(a[i] % 3) s.insert(a[i] % 3);
            }
        }

        int res = 0;
        while(s.size()) {
            if(s.size() == 1) {
                int op = *s.begin();
                s.erase(op);
                res += op / 4;
                op = op % 4;
                if(op == 3)
                    res += 2;
                else if(op == 0)
                    res += 0;
                else
                    res += 1;
                break;
            }
            int op1 = *s.begin();
            int op2 = *(--s.end());
            s.erase((--s.end())), s.erase(s.begin());

            if(op2 >= 3) {
                int x = min(op2 / 3, op1);
                op2 -= 3 * x;
                op1 -= x;
                res += x;
                while(op2 && s.size()) {
                    op1 = *s.begin();
                    s.erase(s.begin());
                    x = min(op2 / 3, op1);
                    op2 -= 3 * x;
                    op1 -= x;
                    res += x;
                }
                if(op2) s.insert(op2);
                if(op1) s.insert(op1);
            }
            else {
                res += 2;
            }
            // for(auto i : s) cerr << i << " ";
            // cerr << endl;
        }

        cout << res << endl;
    }

    return 0;
}
