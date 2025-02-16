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
pair<pair<int, int>, int> a[N];
int res[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{
    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i].first.first);
        read(a[i].first.second);
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);

    int tmp = 1;
    for(int i = 1; i <= n; i++) {
        while(tmp <= n && a[tmp].first.first == i)
            q.push({a[tmp].first.second, a[tmp].second}), tmp++;
        if(!q.size()) {
            cout << -1 << endl;
            return 0;
        }
        if(q.top().first < i) {
            cout << -1 << endl;
            return 0;
        }
        res[q.top().second] = i;
        q.pop();
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    cout << endl;

    return 0;
}
