#include<stdio.h>
#include<stdlib.h>
#define maxsize 12
void QuickSort(int a[maxsize],int low,int high)
{
    int temp,i,j,swap;
    i=low;temp=a[low];
    j=high;
    if(low<high)
    {
        while(i!=j)
        {   
            while((i<j)&&(temp<a[j])) --j;
            if(i<j)
            {   
                swap=a[j];
                a[j]=temp;
                a[i]=swap;
                i=i+1;
            }
            while((i<j)&&(temp>a[i])) ++i;
            if(i<j)
            {
                swap=a[i];
                a[i]=temp;
                a[j]=swap;
                j=j-1;
            }
        }
        a[i]=temp;
        QuickSort(a,low,i-1);
        QuickSort(a,i+1,high);
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
    QuickSort(a,0,11);
    printf("after sort:");
    for(int i=0;i<maxsize;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
