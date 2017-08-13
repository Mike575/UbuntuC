#include<stdio.h>
#include<stdlib.h>
 
 int main()
 {
    int f1=1,f2=1,i;
        for(i=1;i<=20;i++)
            {
                printf("%-12d%-12d",f1,f2);
                if(i%2==0) printf("\n");
                f1=f1+f2;
                f2=f1+f2;
            }
    return 0;
 }

typedef struct rabbit_node
{
    int months_old;
    int rabbit_ID;
    struct rabbit_node *next
}rabbit_node;


/*在尾部新增一个结点*/
/*形参为指向当前结点的指针*/
/**/
void Add_rabbit_at (rabbit_node* current)
{
    struct rabbit_node* new;
    new=(rabbit_node*)malloc(sizeof(rabbit_node));
    new.months_old=0;
    new.rabbit_ID=current.rabbit_ID+1;
    new.next=NULL;
    current.next=new;
} 

/*当前结点months_old增加一*/
/*形参为指向当前结点的指针*/
/*f:ff*/
void Add_onemonth (rabbit_node* current)
{
    current.months_old=current.months_old+1;
}

/*对某一*/
void For_eachnode_run()
{

}


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
