// rabbitFO.c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdio.h>
#include<stdlib.h>


typedef struct rabbit_node
{
	int months_old;
	double ID;
	struct rabbit_node* next;
}rabbit_node;

void Add_rabbit_at(rabbit_node* head);
void Add_onemonth(rabbit_node* current, rabbit_node* head);
void Born_babby(rabbit_node* current, rabbit_node* head);
void For_eachnode_run(rabbit_node* head, void(*fun)(rabbit_node* current, rabbit_node* head));
void Init_node(rabbit_node* head);
void show_node_number(rabbit_node* head);


/*
typedef struct head_node
{
struct rabbit_node *next
};
*/
/*在尾部新增一个结点*/
/*形参为指向链表的某结点的指针*/
/**/
void Add_rabbit_at(rabbit_node* head)
{
	struct rabbit_node* pnew_node;
	pnew_node = (rabbit_node*)malloc(sizeof(rabbit_node));
	struct rabbit_node* current;
	current = (rabbit_node*)malloc(sizeof(rabbit_node));
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}

	pnew_node->months_old = 0;
	pnew_node->ID = current->ID + 1;
	pnew_node->next = NULL;
	current->next = pnew_node;

}

/*当前结点months_old增加一*/
/*形参为指向当前结点的指针*/
/**/
void Add_onemonth(rabbit_node* current, rabbit_node* head)
{
	current->months_old = current->months_old + 1;
}
/*months_old>=3增加一个结点*/
/*形参为当前结点，头结点*/
void Born_babby(rabbit_node* current, rabbit_node* head)
{
	if (current->months_old >= 2)
		Add_rabbit_at(head);
}


/*对某一链表的全体成员执行某一函数*/
/*形参为链表头指针，函数指针*/
void For_eachnode_run(rabbit_node* head, void(*fun)(rabbit_node* current, rabbit_node* head))
{
	struct rabbit_node* current;
	current = (rabbit_node*)malloc(sizeof(rabbit_node));
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
		fun(current, head);

	}
	//   free(current);

}

/*初始化当前结点*/
/*形参为链表表头指针*/
/**/
void Init_node(rabbit_node* head)
{
	head->ID = 0;
	head->months_old = 0;
	head->next = NULL;
}

/*显示链表包含结点个数*/
/*形参为链表头指针*/
/**/
void show_node_number(rabbit_node* head)
{

	struct rabbit_node* current;
	current = (rabbit_node*)malloc(sizeof(rabbit_node));
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	printf("%f\n", current->ID);
	//  free(current);
}

int main(int argc, char *argv[])
{
	struct rabbit_node* head;
	head = (rabbit_node*)malloc(sizeof(rabbit_node));
	Init_node(head);
	Add_rabbit_at(head);
	for (int i = 1; i <= 40; i++)
	{
		For_eachnode_run(head, Add_onemonth);
		For_eachnode_run(head, Born_babby);
		show_node_number(head);
	}


}

