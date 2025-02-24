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
#include <unordered_map>
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

int n, m, h;
int sum1{0}, sum2{0}, sum3{0};
unordered_map<string, bool> s1, s2, s3;

int main()
{
    read(n), read(h), read(m);
    for(int i = 1; i <= n; i++) {
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        if(stoi(str2.substr(0, 4)) != h) continue;
        if(stoi(str2.substr(5, 2)) != m) continue;

        int x = stoi(str3.substr(0, 2));
        int y = stoi(str3.substr(3, 2));
        int z = stoi(str3.substr(6, 2));

        if(x == 7 || x == 8 || (x == 9 && y == 0 && z == 0)) {
            if(!s1[str1]) s1[str1] = 1, sum1++;
        }
        else if(x == 18 || x == 19 || (x == 20 && y == 0 && z == 0)) {
            if(!s1[str1]) s1[str1] = 1, sum1++;
        }
        else if(x == 11 || x == 12 || (x == 13 && y == 0 && z == 0)) {
            if(!s2[str1]) s2[str1] = 1, sum2++;
        }
        else if(x == 22 || x == 23 || x == 0 || (x == 1 && y == 0 && z == 0)) {
            if(!s3[str1]) s3[str1] = 1, sum3++;
        }
    }

    cout << sum1 << " " << sum2 << " " << sum3 << endl;

    return 0;
}
