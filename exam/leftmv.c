#include<stdio.h>

int main()
{
	int a;
	printf("please enter a:\n");
	scanf("%d",&a);
	printf("sizeof(a): %lu\n",sizeof(a));
	printf("a<<0:%d\n",a<<0);
	printf("a<<1:%d\n",a<<1);
	printf("a<<2:%d\n",a<<2);
	printf("a<<3:%d\n",a<<3);
	printf("a<<4:%d\n",a<<4);
	printf("a<<5:%d\n",a<<5);
	printf("a<<33:%d\n",a<<33);
	printf("a<<sizeof(a)*8+1:%d\n",a<<sizeof(a)*8+1);
}

