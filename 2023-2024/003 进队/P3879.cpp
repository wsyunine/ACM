#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int N = 500010;
int n, k,idx;
int son[300010][26];
char str[10010];
int cnt[N][1010];
//vector<int> cnt1[N];
void insert(char str[],int x) {
      int q = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[q][u])son[q][u] = ++idx;
        q = son[q][u];
    }
    cnt[q][x]++;
    //cnt1[q].push_back(x);
}
void  query(char str[]) {
    int q = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[q][u]) {
            cout << endl;
            return ;
        }
        q = son[q][u];
    }
    for (int i = 1; i <= n; i++) if(cnt[q][i]) cout<<i<<" ";
    cout << endl;
    /*int len = cnt1[q].size();
    for (int i = 0; i < len; i++) cout << cnt1[q][i] << " ";
    cout << cnt1[q][len - 1] << endl;*/
    //cout << endl;
    return;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        for (int j = 1; j <= h; j++) {
            scanf("%s ",str);
            insert(str,i);
        }
   }
    cin >> k;
    while(k--) {
        scanf("%s",str);
        query(str);
    }
    return 0;
}