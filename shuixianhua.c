#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct number_chain
{
    int decimal_wei;
    int number_on_wei;
    struct number_chain* next;
}number_chain;


void create_number_chain_on (struct number_chain* Variable_node,double i)
{   
//  static struct number_chain* Variable_node=(struct number_chain*)malloc(sizeof(struct number_chain));
//  Variable_node=head;
    int Variable_decimal_wei=0;

    double Variable_number=i;
    while ((Variable_number/10)!=0)
    {
        struct number_chain* pnew=(struct number_chain*)malloc(sizeof(struct number_chain));
        pnew->decimal_wei=Variable_decimal_wei;
        ++Variable_decimal_wei;
        pnew->number_on_wei=Variable_number-((Variable_number/10)*10);
        pnew->next=NULL;
        Variable_node->next=pnew;
        Variable_node=Variable_node->next;
    }
}

int main()
{
    double Maxnumber;
    double cal_number=0;

    scanf("%lf",&Maxnumber);
    for(double i=0;i<Maxnumber;i++)
    {
        struct number_chain* head=(struct number_chain*)malloc(sizeof(struct number_chain));
        head->decimal_wei=0;
        head->number_on_wei=0;
        head->next=NULL;

        create_number_chain_on(head,i);

        while(head->next!=NULL)
        {
            head=head->next;
            cal_number=cal_number+pow (head->number_on_wei,3);
        }
        if(i==cal_number)
        {
            printf("%lf\n",i);
        }
        cal_number=0;
    }
}

