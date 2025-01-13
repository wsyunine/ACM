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
#define N 5000010
#define LD long double
#define Vector Point
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const LD eps=1e-9;
inline int dcmp(LD a){return a<-eps?-1:(a>eps?1:0);}
inline LD Abs(LD a){return a*dcmp(a);}
struct Point{
    LD x,y;Point(LD X=0,LD Y=0){x=X,y=Y;}
    inline void in(){scanf("%Lf%Lf",&x,&y);}
    inline void out(){printf("%.2Lf %.2Lf",x,y);}
};
inline LD Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
inline LD Len(Vector a){return sqrt(Dot(a,a));}
inline Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
inline Vector operator-(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
inline LD Cro(Vector a,Vector b){return a.x*b.y-a.y*b.x;}

inline bool cmp1(Vector a,Vector b){return a.x==b.x?a.y<b.y:a.x<b.x;}

int n,m;
Point p[N],q[N];
int t;

// inline int ConvexHull(Point *p,int x){
//     sort(p+1,p+1+x,cmp1);
//     int t=0;
//     for(int i=1;i<=x;i++){
//         while(t>1&&dcmp(Cro(res[t]-res[t-1],p[i]-res[t-1]))<=0) t--;
//         res[++t]=p[i];
//     }
//     int st=t;
//     for(int i=n-1;i>=1;i--){
//         while(t>st&&dcmp(Cro(res[t]-res[t-1],p[i]-res[t-1]))<=0) t--;
//         res[++t]=p[i];
//     }
//     return --t;
// }



int main(){

    read(t);
    while(t--){
        read(n);
        LD ans1=0;
        for(int i=1;i<=n;i++) p[i].in();
        // int cnt=ConvexHull(p,n);
        for(int i=2;i<=n;i++){
            ans1+=Len(p[i]-p[i-1]);
        }
        ans1+=Len(p[1]-p[n]);
        read(m);
        for(int i=1;i<=m;i++) q[i].in();
        // cnt=ConvexHull(q,m);
        // cout<<ans1<<endl;

        q[m+1]=q[1];
        LD ans2=Len(q[2]-q[1]);
        for(int i=1,j=3;i<=m;i++){
            while(dcmp(Cro(q[i+1]-q[i],q[j]-q[i])-Cro(q[i+1]-q[i],q[j+1]-q[i]))<=0) j=j<m?j+1:1;
            ans2=max(ans2,max(Len(q[j]-q[i]),Len(q[j]-q[i+1])));
        }
        
        cout<<fixed<<setprecision(15)<<ans1+ans2*2.0*acos(-1)<<endl;
    }

    return 0;
}