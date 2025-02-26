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
int mapp[N];

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        mapp[s[i]]++;
    }

    if(mapp['n'] && mapp['o'] >= 2 && mapp['w'] && mapp['c'] && mapp['d'] && mapp['e'] &&
       mapp['r']) {
        cout << "happy new year" << endl;
    }
    else {
        cout << "I AK IOI" << endl;
    }

    return 0;
}
