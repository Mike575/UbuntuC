// shuixianhua.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "list.h"


void create_bitNum_chain(const List *plist, const double i);

int main(void)
{
	List Variable_bitNum_chain;//用于表示100~1000某一数字
	double MaxSize_num;//用于确定计算范围

					   /*初始化    */
	InitializeList(&Variable_bitNum_chain);
	if (ListIsFull(&Variable_bitNum_chain))//判断能否为该类节点申请新内存
	{
		fprintf(stderr, "No memory available! Bye!\n");
		exit(1);
	}

	/*获取用户输入并存储*/
	puts("Enter MaxSize Number:");
	scanf("%lf", &MaxSize_num);


	/*运行判断输出结果*/
	Node* scan;
	double sum_of_cubes;
	for (double i = 0; i<MaxSize_num; i++)
	{
		create_bitNum_chain(&Variable_bitNum_chain, i);

		scan = Variable_bitNum_chain;
		while (scan->next != NULL)
		{
			sum_of_cubes = sum_of_cubes + pow(scan->item.bit_is_what, 3);
			scan = scan->next;
		}
		if (i == sum_of_cubes)
		{
			printf("%lf\n", i);
		}
		sum_of_cubes = 0;
		EmptyTheList(&Variable_bitNum_chain);
	}
	return 0;
}


void create_bitNum_chain(List *plist, const double i)
{
	//  static struct number_chain* Variable_node=(struct number_chain*)malloc(sizeof(struct number_chain));
	//  Variable_node=head;
	int Variable_where = 0;
	double Variable_number = i;
	while ((Variable_number / 10) != 0)
	{
		Item temp;
		temp.bit_at_where = Variable_where;
		++Variable_where;
		temp.bit_is_what = Variable_number - ((Variable_number / 10) * 10);
		AddItem(temp, plist);   //需要注意 
		Variable_number = Variable_number / 10;
		create_bitNum_chain(plist, Variable_number);
	}
}
