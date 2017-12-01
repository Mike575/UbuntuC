#include<stdio.h>

int main()
{
	unsigned int a;
	printf("please enter data:\n");
	scanf("%ud",&a);
	printf("~0<<a:%x\n",~0<<a);
	printf("~(0<<a):%x\n",~(0<<a));
}
