#include<stdio.h>

int main()
{
	int sum;
	sum=0;
	for(int i=1;i<100;i++)
	{
		sum=sum+1;
		if (i==4)
			continue;
		if (i==9)
			break;
		printf("sum:%d\n",sum);
	}
}


