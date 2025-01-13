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
using namespace std;
#define N 200010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

vector<PII> v1, v2;

int n;
LL a[N];


int main(){
    cin >> n;
    LL lr = INF, rr = INF, rl = INF, ll = INF, ud = INF, du = INF, uu = INF, dd = INF, U = INF, R = INF, D = INF, L = INF;
    for (int i = 1; i <= n; i++)
    {
        LL x, y;
        char d;
        cin >> x >> y >> d;
        if (d == 'N') {
            if (uu == INF || uu < y)
                uu = y;
            if (ud == INF || ud > y)
                ud = y;
            if (L > x || L == INF)
                L = x;
            if (R < x || R == INF)
                R = x;
        }
        else if (d == 'S'){
            if (du == INF || du < y)
                du = y;
            if (dd == INF || dd > y)
                dd = y;
            if (L > x || L == INF)
                L = x;
            if (R < x || R == INF)
                R = x;
        }      
        else if (d == 'E') {
            if (rr == INF || rr < x)
                rr = x;
            if (rl == INF || rl > x)
                rl = x;
            if (D > y || D == INF)
                D = y;
            if (U < y || U == INF)
                U = y;
        }
        else if (d == 'W') {
            if (lr == INF || lr < x)
                lr = x;
            if (ll == INF || ll > x)
                ll = x;
            if (D > y || D == INF)
                D = y;
            if (U < y || D == INF)
                U = y;
        }
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;        
    }

    if (lr != INF)
        v1.push_back({lr, -1});
    if (ll != INF)
        v1.push_back({ll, -1});
    if (rr != INF)
        v1.push_back({rr, 1});
    if (rl != INF)
        v1.push_back({rl, 1});
    if (L != INF)
        v1.push_back({L, 0});
    if (R != INF)
        v1.push_back({R, 0});

    if (ud != INF)
        v2.push_back({ud, 1});
    if (uu != INF)
        v2.push_back({uu, 1});
    if (du != INF)
        v2.push_back({du, -1});
    if (dd != INF)
        v2.push_back({dd, -1});
    if (U != INF)
        v2.push_back({U, 0});
    if (D != INF)
        v2.push_back({D, 0});
    queue<LL> tt;
    for (auto i : v1)
    {
        for (auto j : v1)
        {
            if (i == j)
                continue;
            LL a1 = i.first, a2 = i.second;
            LL b1 = j.first, b2 = j.second;
            if (a2 == b2)
                continue;
            LL t = (a1 - b1) / (-a2 + b2);
            if (t < 0)
                continue;
            tt.push(t);
            if (t * (-a2 + b2) != a1 - b1)
                tt.push(t + 1);
        }
    }
    for (auto i : v2)
    {
        for (auto j : v2)
        {
            if (i == j)
                continue;
            LL a1 = i.first, a2 = i.second;
            LL b1 = j.first, b2 = j.second;
            if (a2 == b2)
                continue;
            LL t = (a1 - b1) / (-a2 + b2);
            if (t < 0)
                continue;
            tt.push(t);
            if (t * (-a2 + b2) != a1 - b1)
                tt.push(t + 1);
        }
    }
    LL ans = INF;
    while (!tt.empty())
    {
        LL t = tt.front();
        //cout << t << endl;
        tt.pop();
        LL rmx = -INF, rmn = INF, cmx = -INF, cmn = INF;
        for (auto i : v1)
        {
            LL x = i.first + i.second * t;
            rmx = max(x, rmx);
            rmn = min(x, rmn);
        }
        for (auto i : v2)
        {
            LL x = i.first + i.second * t;
            cmx = max(x, cmx);
            cmn = min(x, cmn);
        }
        //if (t == 2)
        //{
        //    cout << rmx << " " << rmn << " " << cmx << " " << cmn << endl;
        //}
        ans = min(ans, (cmx - cmn + rmx - rmn) * 2);
    }        
    cout << ans << endl;
    //cout << ll << " " << lr << " " << rl << " " << rr << endl;
    //cout << uu << " " << ud << " " << du << " " << dd << endl;
    //cout << R << " " << L << " " << D << " " << U << endl;


    return 0;
}