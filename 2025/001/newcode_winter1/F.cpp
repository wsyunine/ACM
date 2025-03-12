#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
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

int T;
int n;
int a[N];

void solve() {
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }

    int opt=1,l=1,res=0;
    int num1=a[1],sum1=1;
    while(opt<n&&a[opt+1]==num1) sum1++,opt++;
    if(opt==n){
        cout<<0<<endl;
        return;
    }
    opt++;
    int num2=a[opt],sum2=1;
    while(opt<n&&(a[opt+1]==num1||a[opt+1]==num2)){
        if(a[opt+1]==num1){
            sum1++;
        }else sum2++;
        opt++;
    }
    vector<int> ps(n+1);
    unordered_map<int,int> mapp;
    mapp[0]++;
    // cout<<l<<" "<<opt<<" "<<num1<<" "<<num2<<endl;
    for(int i=l;i<=opt;i++){
        if(a[i]==num1) ps[i]=ps[i-1]+1;
        else ps[i]=ps[i-1]-1;
        res+=mapp[ps[i]];
        mapp[ps[i]]++;
    }
    for(int i=l;i<=opt;i++) mapp[ps[i]]--;
    for(int i=l;i<=opt;i++) ps[i]=0;
    while(opt<n){
        while(l<=n&&(sum1&&sum2)){
            if(a[l]==num1) sum1--;
            else if(a[l]==num2) sum2--;
            l++;
        }
        if(sum1==0){
            swap(num1,num2);
            swap(sum1,sum2);
        }
        opt++;
        num2=a[opt],sum2=1;
        while(opt<n&&(a[opt+1]==num1||a[opt+1]==num2)){
            if(a[opt+1]==num1){
                sum1++;
            }else sum2++;
            opt++;
        }
        // cout<<l<<" "<<opt<<" "<<num1<<" "<<num2<<endl;
        for(int i=l;i<=opt;i++){
            if(a[i]==num1) ps[i]=ps[i-1]+1;
            else ps[i]=ps[i-1]-1;
            res+=mapp[ps[i]];
            mapp[ps[i]]++;
        }
        for(int i=l;i<=opt;i++) mapp[ps[i]]--;
        for(int i=l;i<=opt;i++) ps[i]=0;
    }

    cout<<res<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}