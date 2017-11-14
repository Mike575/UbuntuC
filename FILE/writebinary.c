#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
struct X_type
{
	int x1;
	int x2;
	int x3;
	int x4;
}Xline[SIZE];

int main()
{
	FILE* fp;

	if((fp=fopen("rectangle.dat","wb"))==NULL)
	{
		printf("cannot open files\n");
		exit(0);
	}
	printf("please enter data of rectangle X1 x2 x3 x4 for eachline:\n");
	for(int i=0;i<SIZE;i++)
		scanf("%d%d%d%d",&Xline[i].x1,&Xline[i].x2,&Xline[i].x3,&Xline[i].x4);
	for(int i=0;i<SIZE;i++)
		if(fwrite(&Xline[i],sizeof(struct X_type),1,fp)!=1)
			printf("file write error\n");
	fclose(fp);
}


