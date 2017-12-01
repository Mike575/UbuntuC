#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[100];
	int length;
	//fgets(str,7,stdin);
	str[0]='a';
	str[1]='b';
	str[2]='c';
	str[3]='\n';
	str[4]='\0';
	str[5]='d';
	str[6]='e';
	length=strlen(str);
	printf("strlenth is %d\n",length);
	return 0;
}
