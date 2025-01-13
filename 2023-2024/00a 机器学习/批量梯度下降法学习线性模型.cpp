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

//f(x;theta)
double func(vector<double> x,vector<double> theta){
    int length_x=x.size();
    double ans=0;
    for(int i=0;i<length_x;i++){
        ans+=x[i]*theta[i];
    }
    ans+=theta[length_x];
    return ans;
}

//对损失函数关于第k个参数求偏导
double delta_loss_func(double y,vector<double> x,vector<double> theta,int k){
    double ans=0;
    int length_x=x.size();
    ans=func(x,theta)-y;
    if(k!=length_x) ans*=x[k];
    return ans;
}

//梯度下降求各参数
vector<double> gradient_descent(vector<vector<double>> data,vector<double> res){
    int t=2000,length_x=data[0].size(),data_size=data.size();
    double learn_rate=0.05;
    vector<double> theta_now(length_x+1);
    srand(clock());
    for(int i=0;i<=length_x;i++) theta_now[i]=rand()%10;
    while(t--){
        for(int theta_i=0;theta_i<=length_x;theta_i++){
            double des=0;
            for(int data_i=0;data_i<data_size;data_i++){
                des+=delta_loss_func(res[data_i],data[data_i],theta_now,theta_i);
            }
            des*=1.0/(double)data_size*(double)learn_rate;
            theta_now[theta_i]-=des;
        }
    }
    return theta_now;
}

int main(){

    int n;int m;int q;
    read(n),read(m);
    vector<vector<double>> data(n,vector<double>(m));
    vector<double> res(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>data[i][j];
        cin>>res[i];
    }

    vector<double> theta=gradient_descent(data,res);

    // 拟合出的各参数值
    for(auto i:theta) cout<<i<<endl;

    read(q);

    for(int i=1;i<=q;i++){
        vector<double> x(m);
        for(int j=0;j<m;j++) cin>>x[j];
        cout<<func(x,theta)<<endl;
    }

    return 0;
}

/*

f(x)=2x+1
10 1
1 3
2 5
3 7
4 9
5 11
6 13 
7 15
8 17
9 19
10 21

f(x,y)=2x+y+3
7 2
1 1 6
1 2 7
1 3 8
2 1 8
3 1 10
2 2 9
3 3 12

*/