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

template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
const int N = 1e6 + 10;
string s;
int a[N];
stack<int> stk;
int num1[N], num0[N];

int main(){

    int T;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == ')')
                a[i + 1] = 0;
            else
                a[i + 1] = 1;
        }
        while (!stk.empty())
            stk.pop();
        for (int i = 0; i <= n; i++)
            num0[i] = num1[i] = 0;
        //int num0 = 0, num1 = 0;
        bool ans = false;
        for (int i = 1; i <= n; i++)
        {
            if (stk.empty() || stk.top() != a[i])
                stk.push(a[i]);
            else {
                num0[stk.size()] = num1[stk.size()] = 0;
                stk.pop();
                if (a[i] == 0)
                    num0[stk.size()]++;
                else
                    num1[stk.size()]++;
                if (num0[stk.size()] >= 2 || num1[stk.size()] >= 2)
                    ans = true;
            }
        }
        if (stk.empty() && !ans)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}