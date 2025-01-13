#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3e6 + 10;

struct Q
{
    int t;
    char x;
} q[N];
int hh = 0, tt = 0;
char s[N];

int main()
{
    int n;
    cin >> n;
    scanf("%s", s + 1);
    int ans = 0;
    int numf;
    for (int i = 1; i <= n; i++)
    {
        if (hh - tt == 6)
        {
            if (q[tt].x == 'F')
                numf--;
            ans++;
            tt++;
        }
        q[++hh].x = s[i];
        if (s[i] == 'A' || s[i] == 'D')
            q[hh].t = 2;
        else if (s[i] == 'B')
            q[hh].t = 3;
        else if (s[i] == 'E' || s[i] == 'C')
            q[hh].t = 1;

        if (numf)
        {
            for (int i = tt + 1; i <= hh; i++)
            {

                if (q[i].t > 0 && q[i].t - numf <= 0)
                {
                    if (q[i].x == 'A')
                        ans += 1;
                    else if (q[i].x == 'B')
                        ans += 2;
                    else if (q[i].x == 'C')
                    {
                        s[++n] = 'A';
                        s[++n] = 'B';
                    }
                    else if (q[i].x == 'D')
                    {
                        int st[8];
                        int kinds = 0;
                        for (int i = tt + 1; i <= hh; i++)
                            st[q[i].x - 'A' + 1] = true;
                        for (int i = 1; i <= 7; i++)
                            if (st[i])
                                kinds++;
                        ans += kinds;
                    }
                    else if (q[i].x == 'E')
                        s[++n] = 'F';
                }
                q[i].t -= numf;
            }
        }

        if (s[i] == 'G')
        {
            for (int i = tt + 1; i <= hh; i++)
            {
                q[i].t = 0;
                if (q[i].x == 'A')
                    ans += 1;
                else if (q[i].x == 'B')
                    ans += 2;
                else if (q[i].x == 'C')
                {
                    s[++n] = 'A';
                    s[++n] = 'B';
                }
                else if (q[i].x == 'D')
                {
                    int st[8];
                    int kinds = 0;
                    for (int i = tt + 1; i <= hh; i++)
                        st[q[i].x - 'A' + 1] = true;
                    for (int i = 1; i <= 7; i++)
                        if (st[i])
                            kinds++;
                    ans += kinds;
                }
                else if (q[i].x == 'E')
                    s[++n] = 'F';
            }
        }
        if (s[i] == 'F')
            numf++;
    }
    cout << ans << endl;
    return 0;
}