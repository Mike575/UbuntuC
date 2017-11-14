#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
struct Student_type
{
	char name[10];
	int num;
	int age;
}stud[SIZE];

void save()
{
	FILE* fp;
	int i;
	if((fp=fopen("stu.dat","wb"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for(i=0;i<SIZE;i++)
		if(fwrite(&stud[i],sizeof(struct Student_type),1,fp)!=1)
			printf("file write error\n");
	fclose(fp);
}
int main()
{
	int i;
	printf("Please enter data of students:\n");
	for(i=0;i<SIZE;i++)
		scanf("%s%d%d",stud[i].name,&stud[i].num,&stud[i].age);
	save();
	return 0;
}

