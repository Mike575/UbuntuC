#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
struct Y_type
{
	int y1;
	int y2;
	int y3;
	int y4;
}Yline[SIZE];

int main()
{
	FILE* fp;

	if((fp=fopen("rectangle.txt","w"))==NULL)
	{
		printf("cannot open files\n");
		exit(0);
	}
	printf("please enter data of rectangle y1 y2 y3 y4 for eachline:\n");
	for(int i=0;i<SIZE;i++)
		scanf("%d%d%d%d",&Yline[i].y1,&Yline[i].y2,&Yline[i].y3,&Yline[i].y4);
	for(int i=0;i<SIZE;i++)
		if(fprintf(fp,"%d%d%d%d",Yline[i].y1,Yline[i].y2,Yline[i].y3,Yline[i].y4)!=4)
			printf("file write error\n");
	fclose(fp);
}


