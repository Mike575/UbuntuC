#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

int main(void)
{
	char file[SLEN];
	char ch;
	FILE* fp;
	long count,last;

	puts("Enter the name of the file to be processed:");
	scanf("%80s",file);
	getchar();
	if((fp=fopen(file,"rb"))==NULL)
	{
	printf("reverse can't open %s\n",file);
	exit(EXIT_FAILURE);
	}

	fseek(fp,0L,SEEK_END);
	last=ftell(fp);
	printf("lastis:%ld",last);
	for(count=1L;count<=last;count++) 
	{
	fseek(fp,-count,SEEK_END);//under to top
	ch=getc(fp);
	if(1)	
//	if(ch!=CNTL_Z&&ch!='\r')
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	return 0;
}
