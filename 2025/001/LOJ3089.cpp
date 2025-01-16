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

int n, m;
int trie[N][11], cnt = 0, fail[N], flg[N];

void insert(char* s)
{
    int x = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        int ch = s[i] - '0';
        if(!trie[x][ch]) trie[x][ch] = ++cnt;
        x = trie[x][ch];
    }
    flg[x]++;
}

void getfail()
{
    queue<int> q;
    for(int i = 0; i <= 9; i++) {
        if(trie[0][i]) fail[trie[0][i]] = 0, q.push(trie[0][i]);
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        int fafail = fail[x];
        for(int i = 0; i <= 9; i++) {
            int y = trie[x][i];
            if(!y) {
                trie[x][i] = trie[fafail][i];
                continue;
            }
            fail[y] = trie[fafail][i];
            q.push(y);
        }
    }
}

int main() { return 0; }
