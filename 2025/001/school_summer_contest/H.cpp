#include <bits/stdc++.h>

using namespace std;

#define N 500010

long long n;
int t;
unordered_map<long long, int> mapp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tmp = 3;
    while(tmp < 1e18) {
        mapp[tmp] = 1;
        tmp = tmp * 2 - 1;
    }

    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 3)
            cout << "xr" << endl;
        else if(n == 5)
            cout << "xr" << endl;
        else if(mapp[n]) {
            cout << "xr" << endl;
        }
        else {
            cout << "wty" << endl;
        }
    }

    return 0;
}
