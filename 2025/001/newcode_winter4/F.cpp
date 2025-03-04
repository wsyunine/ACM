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
int n, p, k;
int a[N];
pair<int, int> nt[N];
vector<int> ans;

bool check(int x)
{
    cout << x << endl;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int opl = x - a[i] + 1, opr = p - a[i] - 1;
        cout << " " << opl << " " << opr << endl;
        if(opl >= 0) {
            int rr = upper_bound(a + 1, a + 1 + n, opr) - 1 - a;
            int ll = lower_bound(a + 1, a + 1 + n, opl) - a;
            nt[i] = {ll, rr};
            res += rr - ll + 1;
            cout << "! " << ll << " " << rr << endl;
            if(ll <= i && rr >= i) res--;
        }
        opl = x + p - a[i] + 1, opr = 2 * p - a[i] - 1;
        cout << " " << opl << " " << opr << endl;
        if(opl < p) {
            int rr = upper_bound(a + 1, a + 1 + n, opr) - 1 - a;
            int ll = lower_bound(a + 1, a + 1 + n, opl) - a;
            nt[i] = {ll, rr};
            res += rr - ll + 1;
            cout << "! " << ll << " " << rr << endl;
            if(ll <= i && rr >= i) res--;
        }
        cout << res << " ";
        if(res >= k) return 1;
    }
    cout << res << endl;
    return 0;
}

int main()
{
    read(t);
    while(t--) {
        ans.clear();
        read(n), read(p), read(k);
        long long s = n * (n - 1) / 2;
        for(int i = 1; i <= n; i++) read(a[i]), a[i] = a[i] % p;
        sort(a + 1, a + 1 + n);

        int l = -1, r = p - 2;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(mid))
                l = mid + 1;
            else
                r = mid;
        }

        check(l);
        for(int i = 1; i <= n; i++) {
            for(int j = nt[i].first; j <= nt[i].second; j++) {
                if(i == j) continue;
                if((a[i] + a[j]) % p >= k) ans.push_back((a[i] + a[j]) % p);
            }
        }

        while(ans.size() < min(s, (long long)k)) ans.push_back(l);
        while(ans.size() < k) ans.push_back(-1);

        for(auto i : ans) printf("%d ", i);
    }

    return 0;
}
