#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e6+10;
int q;
char s[N];
int n;
int ne[N];
int ans;
void kmp(int first,int last){
    memset(ne,0,sizeof ne);
   //  cout<<first+1<<" "<<n<<"----"<<endl;
    for(int i=last,j=first;i<=n;i++){

    while((j-first)&&(s[j+1]!=s[i]))j=ne[j];
        if(s[j+1]==s[i])j++;
        ne[i]=j;
        if(ne[i]>=first+1)ans--;
    }
}
int main(){
    cin>>q;
    while(q--){
        cin>>(s+1);
        n=strlen(s+1);
        ans=(n+1)*n/2;
       for(int i=0;i<=n-2;i++){      
         kmp(i,i+2);}
       cout<<ans<<endl;
    }
}