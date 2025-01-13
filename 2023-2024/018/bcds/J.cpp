#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

string str;

int main(){

    int n;
    cin>>str;
    cin>>n;

    while(n--){
        cout<<str<<endl;
        char s=str[0];
        for(int i=0;i<=str.length();i++){
            str[i]=str[i+1];
        }
        str[str.length()-1]=s;
    }



    return 0;
}