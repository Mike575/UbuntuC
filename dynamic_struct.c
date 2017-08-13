#include<stdio.h>
#include<stdlib.h>

typedef struct sf 
{
    int n;
    char c;
}fc;

int main(int argc,char *argv[])
{
    int i=0;
    struct sf xx[8];
    fc *yy;
    
    for(i=0;i<8;i++)
    {
        xx[i].n=i;
        (*(xx+i)).c='a'+i;
    }//abcdefgh
    for(i--;i>-1;i--)
        printf("%d%c ",(*(xx+i)).n,xx[i].c);
    puts("");

    yy=(fc*)malloc(10*sizeof(fc));
    if(yy==NULL)
    {
        puts("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }//申请失败则提示并退出程序

    for(i=0;i<10;i++)
    {
        yy[i].n=i;
        (*(yy+i)).c='A'+i;
    }

    for(i--;i>-1;i--)
        printf("%d%c ",(*(yy+i)).n,yy[i].c);
    free(yy);
    puts("");

    return 1;
}
