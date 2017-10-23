#include<stdio.h>
#include<stdlib.h>
#define maxsize 15
void Sift(int R[],int low,int high)
{   
    int temp,i,j;
    int swap;
    i=low;
    j=2*i+1;
    temp=R[low];
    while(j<high)
    {
        if((j<high-1)&&(R[j+1]>R[j])) ++j;
        if(temp<R[j])
            {
                R[i]=R[j];
                i=j;
                j=2*i+1;
            }
         else
             break;
    }
    R[i]=temp;
}

void heapSort(int R[],int n)
{
    int swap;
    for(int i=(n/2-1);i>=0;i--)
        Sift(R,i,n);
    for(int i=n-1;i>=1;i--)
    {
        swap=R[i];
        R[i]=R[0];
        R[0]=swap;
        Sift(R,0,i);
        printf("\nSort%d: ",i);
        for(int ii=0;ii<maxsize;ii++)
        {
            printf("%d ",R[ii]);
        }
    }


}

int main(void)
{
    int R[maxsize];
    for(int i=0;i<maxsize;i++) R[i]=0;
    for(int i=0;i<maxsize;i++)
    {
        scanf("%d",&(R[i]));
    }
    printf("before sort:");
    for(int i=0;i<maxsize;i++)
    {
        printf("%d ",R[i]);
    }
    printf("\n");
    heapSort(R,15);
    printf("after sort:");
    for(int i=0;i<maxsize;i++)
    {
        printf("%d ",R[i]);
    }
    printf("\n");
}
