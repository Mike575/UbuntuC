#include<stdio.h>

int main()
{
    double h=100;
    double sum=100;
    h=h/2;
    for(int i=2;i<=10;i++)
    {
        sum=sum+2*h;
        h=h/2;
    
    }
    printf("sum:%f\n",sum);
    printf("10th:%f\n",h);
    return 0;
}
