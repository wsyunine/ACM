#include<iostream>
int main(){
    int n,a[1001],cnt[1001],i,j,ans=0,ansi=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cnt[i]=0;
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]==a[j]) cnt[i]++;
        }
    }
    for(i=0;i<n;i++){
        if(ans<cnt[i]){
            ans=cnt[i];
            ansi=a[i];
        }
    }
    printf("%d %d\n",ansi,ans);

    return 0;
}




