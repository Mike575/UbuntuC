#include<stdio.h>
#include<math.h>
int isprime (int estimate_number)
{
    int i=0;
    int s=0;
    int k=0;
    k=sqrt(estimate_number);
    for(i=2;i<=k;i++)
    {
        if((estimate_number%i)==0)
        {
            s=1;
            break;
        }
    }
    if(s==0){
        return estimate_number; 
    }else{
        return 0;
    }
}
int main()
{   
    int max_size_number=0;
    scanf("%d",&max_size_number);
    for(int i=2;i<max_size_number;i++)
     {
         if(isprime(i))
         {

             printf("%d\n",i);
         }
     }
    return 0;
}
// the answer is more than one
