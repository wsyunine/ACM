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
#include<unordered_map>
using namespace std;
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

#define int long long

int a[N];
int n, k;
unordered_map<int, int> mp1, mp2;
priority_queue<int> low;
priority_queue<int, vector<int>, greater<int>> high;

bool check(int mid)
{
    //cout << mid << endl;
    int sumlow = 0, sumhigh = 0;
    int sizelow = 0, sizehigh = 0;
    mp1.clear(), mp2.clear();
    while (!low.empty())
        low.pop();
    while (!high.empty())
        high.pop();
    for (int i = 1; i <= n; i++)
    {
        while (!high.empty() && mp1[high.top()] == 0)
        {
            //mp1[high.top()]--;
            
            high.pop();
        }
        while (!low.empty() && mp2[low.top()] == 0)
        {
            //mp2[low.top()]--;
            low.pop();
        }
        if (sizelow + sizehigh == mid)
        {
            //cout << sumhigh - sumlow << endl;
            //cout << high.top() << "top" << endl;
            //cout << endl;
            if (mid % 2 == 0){
                if (sumhigh - sumlow <= k){
                    //cout << "OOOooo" << endl;
                    return false;
                }                
            }
            else
                if (sumhigh - sumlow - high.top() <= k)
                {
                    //cout << "OOOooo" << endl;
                    return false;
                }
            int x = a[i - mid];
            if (x >= high.top()) {
                sizehigh--;
                sumhigh -= x;
                mp1[x]--;
                while (!high.empty() && mp1[high.top()] == 0)
                    high.pop();
            }
            else {
                sizelow --;
                sumlow -= x;
                mp2[x]--;
                while (!low.empty() && mp2[low.top()] == 0)
                    low.pop();
            }
        }
        //cout << sumlow << " " << sumhigh << endl;
        //cout << endl;

        if (sizelow < sizehigh) {
            sizelow ++;
            high.push(a[i]);
            sumhigh += a[i];
            mp1[a[i]]++;
            mp1[high.top()]--;
            mp2[high.top()]++;
            sumhigh -= high.top();
            sumlow += high.top();
            low.push(high.top());
            high.pop();
        }
        else {
            sizehigh++;
            low.push(a[i]);
            sumlow += a[i];
            mp2[a[i]]++;
            mp2[low.top()]--;
            mp1[low.top()]++;
            sumlow -= low.top();
            sumhigh += low.top();
            high.push(low.top());
            low.pop();
        }
        //cout << sumlow << " " << sumhigh << endl;
    }
                if (mid % 2 == 0){
                if (sumhigh - sumlow <= k){
                    //cout << "OOOooo" << endl;
                    return false;
                }                
            }
            else
                if (sumhigh - sumlow - high.top() <= k)
                {
                    //cout << "OOOooo" << endl;
                    return false;
                }
    return true;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%lld %lld", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]); 
            a[i] -= i;          
        }


        int l = 0, r = n;

        //if (check(4))
        //    cout << "OOO" << endl;

        //cout << endl << endl;

        while(l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        //if (!check(l + 1))
        //    cout << l + 1 << endl;
        if (!check(l))
            cout << l << endl;
        else
            cout << l - 1 << endl;
    }
}