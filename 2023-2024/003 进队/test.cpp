#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
int main(){
    
    double money,year,rate,interest;
    
    scanf("%lf%lf%lf",&money,&year,&rate);

    interest=money*pow(1.0+rate,year)-money;

    printf("insterest = %.2lf\n",interest);

    return 0;
}