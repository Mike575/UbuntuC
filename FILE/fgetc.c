#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp;
	char ch;
	fp=fopen("rectangle.txt","r");
	//circle will be stopped,after ch meets ffff ffff
	for(int i=0;(ch=fgetc(fp))!=EOF;i++)
		putchar(ch);
	fclose(fp);
}

