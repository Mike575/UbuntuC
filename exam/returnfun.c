#include<stdio.h>

int fun()
{
	return fun();
}

int main()
{
	fun();
	return 0;
}
