#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

#define N 500010

template <typename T>
inline void read(T &x)
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
int m;
int q;

int mapp[70][2500];

signed main()
{
    read(n), read(m);
    read(q);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            read(mapp[i][j]);
        }
        sort(mapp[i] + 1, mapp[i] + 1 + m);
    }

    while(q--) {
        int a, b, c, d, k;
        read(a), read(b), read(c), read(d), read(k);

        int l = -1e8, r = 1e8;
        int op1, op2, op3, op4;
        while(l < r) {
            int mid = (l + r) >> 1;
            op1 = upper_bound(mapp[a] + 1, mapp[a] + 1 + m, mid) - mapp[a] - 1;
            op2 = upper_bound(mapp[b] + 1, mapp[b] + 1 + m, mid) - mapp[b] - 1;
            op3 = upper_bound(mapp[c] + 1, mapp[c] + 1 + m, mid) - mapp[c] - 1;
            op4 = upper_bound(mapp[d] + 1, mapp[d] + 1 + m, mid) - mapp[d] - 1;
            if(op1 + op2 + op3 + op4 >= k)
                r = mid;
            else
                l = mid + 1;
        }

        printf("%d\n", l);
    }

    return 0;
}
