#include<stdio.h>
#include<stdlib.h>
#define maxsize 12
void SelectSort(int a[maxsize],int num)
{
    int temp,k;
    for(int i=0;i<num;i++)
        {
            k=i;
            for(int j=i+1;j<num;j++)
            {
                if(a[j]<a[k])
                {
                    k=j;
                }
            }
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
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
    SelectSort(a,12);
    printf("after sort:");
    for(int i=0;i<maxsize;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
