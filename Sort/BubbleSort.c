#include<stdio.h>
#include<stdlib.h>
#define maxsize 12
void BubbleSort(int a[maxsize],int n)
{
    int temp=0;
    int flag=0;
    for(int i=n-1;i>0;i--)
    {
        flag=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                flag=1;
            }
        }
        if (flag==0) return;
    }
}

int main(void)
{
    int a[maxsize];
    for(int i=0;i<maxsize;i++) a[i]=0;
    for(int i=0;i<maxsize;i++)
    {
        scanf("%d",&(a[i]));
    }
    printf("before sort:");
    for(int i=0;i<maxsize;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    BubbleSort(a,maxsize);
    printf("after sort:");
    for(int i=0;i<maxsize;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
