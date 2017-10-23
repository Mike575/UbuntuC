#include<stdio.h>

int issquare(int estimate_number)
{
    int i=0;
    while( i<=(estimate_number/2))
    {
        if(i*i==estimate_number)
        {
            return i; 
        }
        ++i;
    }
    return 0;
}
int main()
{   
    int max_size_number=0;
    scanf("%d",&max_size_number);
    for(int i=1;i<max_size_number;i++)
     {
         if(issquare(i+100)&&issquare(i+100+168))
         {

             printf("%d^2=%d\n",issquare(i+100+168),i+168+100);
             printf("%d^2=%d\n",issquare(i+100),i+100);
         }
     }
    return 0;
}
// the answer is more than one
