#include<stdio.h>
#define maxsize 12
void PNsort(int R[])
{
    int i,j;
    int temp;
    i=0;j=maxsize-1;
    while(i<j)
    {
               
            while((i<j)&&(R[i]>0))   ++i;
            while((i<j)&&(R[j]<0))   --j;
            temp=R[i];
            R[i]=R[j];
            R[j]=temp;
            ++i;--j;
    }
}

void input(int R[])
{
    for(int i=0;i<maxsize;i++)
        scanf("%d",&R[i]);
}
void output(int R[])
{
    for(int i=0;i<maxsize;i++)
        printf("%d ",R[i]);
    printf("\n");
}
int main(void)
{
    int b;
    int R[12];
    input(R);
    printf("before sort:");
    output(R);
    PNsort(R);
    printf("after sort:");  
    output(R);
    return 0;
}
