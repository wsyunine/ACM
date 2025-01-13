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
#include<unordered_map>
using namespace std;
typedef long long LL;
#define N 2010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

struct Node {
    int cnt;
    LL y;
    LL w[N], v[N]; // v = value
}th[N];

struct Point {
    LL x, y;
}p1[N], p2[N];
int cnp1, cnp2;
int yyy[N];
int num = 0;

LL ans[N];
LL f[N][N];

unordered_map<LL, int> mp; 

bool cmp(Point a, Point b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else
        return llabs(a.x) < llabs(b.x);
}

void init(struct Point* p, int cnt)
{
    for (int i = 1; i <= cnt; i++)
    {
        int yy = mp[p[i].y];
        auto &now = th[yy];
        now.y = p[i].y;
        now.w[++now.cnt] = now.w[now.cnt - 1] + 1;
        now.v[now.cnt] = llabs(p[i].x);
    }
    cnt++;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        LL x, y;
        scanf("%lld %lld", &x, &y);
        yyy[i] = y;
        if (x >= 0) {
            p1[++cnp1].x = x;
            p1[++cnp1].y = y;
        }
        else {
            p2[++cnp2].x = x;
            p2[++cnp2].y = y;
        }
    }
    sort(yyy + 1, yyy + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(yyy[i]) == mp.end()) {
            mp[yyy[i]] = ++num;
        }
    }
    sort(p1 + 1, p1 + 1 + cnp1, cmp);
    sort(p2 + 1, p2 + 1 + cnp2, cmp);

    init(p1, cnp1);
    init(p2, cnp2);

    memset(ans, 0x3f, sizeof ans);
    ans[0] = 0;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= num; i++)
        f[i][0] = 0;

    for (int i = 1; i <= num; i++)
    {
        LL add = th[i].y - th[i - 1].y;
        auto &now = th[i];
        for (int j = n; j >= 0; j--)
        {
            for (int k = 1; k <= now.cnt; k++)
            {
                if (now.w[k] <= j) {
                    ans[j] = min(ans[j], f[i][j - now.w[k]] + now.v[k] + add);
                    f[i][j] = min(f[i][j], f[i][j - now.w[k]] + now.v[k] * 2 + add);
                }
            }
        }
    }
    cout << ans[n] << endl;
    return 0;
}