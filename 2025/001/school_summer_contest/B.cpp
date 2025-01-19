#include <bits/stdc++.h>
using namespace std;

#define N 500010

int n;
int t;

int main()
{
    cin >> t;
    while(t--) {
        cin >> n;
        if(n & 1) {
            int tmp = n, s = 0;
            for(int i = 2; i <= n / i; i++) {
                if(tmp % i == 0) {
                    s = i;
                    break;
                }
            }
            if(s)
                cout << s << endl;
            else
                cout << n << endl;
        }
        else {
            cout << 2 << endl;
        }
    }

    return 0;
}
