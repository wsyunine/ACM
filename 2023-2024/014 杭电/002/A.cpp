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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    read(t);
    while(t--){
        read(n);
        if(n < 6){
            for (int i = 1; i <= n; i++)
                cout << 1 << " " << i + 1 << endl;
        }else if (n < 9) {
            cout << "1 2\n1 3\n1 4\n1 5\n";
            for (int i = 7; i <= n; i++)
                cout << "1 " << i-1 << endl;
            cout << "2 3\n2 4\n";
        }else if(n < 12){
            cout<<"1 2\n1 3\n1 4\n1 5\n";
            for (int i = 10; i <= n; i++)
                cout << "1 " << i - 4 << endl;
            cout << "2 3\n2 4\n2 5\n3 4\n3 5\n";
        }else if(n < 15){
            cout<<"1 2\n1 3\n1 4\n1 5\n1 6\n";
            for (int i = 13; i <= n; i++)
                cout << "1 " << i - 7 << endl;
            cout <<"2 3\n2 4\n2 5\n2 6\n3 4\n3 5\n3 6\n";
        }else if(n<18){
            cout<<"1 2\n1 3\n1 4\n1 5\n1 6\n"; 
            for (int i = 16; i <= n; i++)
                cout << "1 " << i - 9 << endl;
            cout <<"2 3\n2 4\n2 5\n2 6\n3 4\n3 5\n3 6\n4 5\n4 6\n5 6\n";
            //cout<<"1 2\n1 3\n1 4\n1 5\n1 6\n1 7\n\n4 7\n5 6\n5 7\n6 7\n";
        }else if(n < 21){
            cout<<"1 2\n1 3\n1 4\n1 5\n1 6\n1 7"<<endl;
            for (int i = 19; i <= n; i++)
                cout << "1 " << i - 11 << endl;
            cout << "2 3\n2 4\n2 5\n2 6\n2 7\n3 4\n3 5\n3 6\n3 7\n4 5\n4 6\n5 6\n";
            //for(int i=8;i<=n;i++) cout<<"1 "<<i<<endl;
            //
        }else if (n >= 21) {
            cout<<"1 2\n1 3\n1 4\n1 5\n1 6\n1 7"<<endl;
            int cnt = 24;
            while (cnt <= n)
            {
                cout << "1 " << cnt / 3 << endl;
                cnt += 3;
            }
            int mod = n % 3;
            int start = n / 3;
            for (int i = 1; i <= mod; i++)
                cout << "1 " << start + i << endl;
            cout << "2 3\n2 4\n2 5\n2 6\n2 7\n";
            cnt = 24;
            while (cnt <= n)
            {
                cout << "2 " << cnt / 3 << endl;
                cnt += 3;
            }
            cout << "3 4\n3 5\n3 6\n3 7\n";
            cnt = 24;
            while (cnt <= n)
            {
                cout << "3 " << cnt / 3 << endl;
                cnt += 3;
            }


                cout<<"4 5\n4 6\n4 7\n5 6\n5 7\n6 7\n";
        }
    }
    
    return 0;
}