#include<stdio.h>
#include<stdlib.h>

void save_getc(FILE* fpin,FILE* fpout)
{
	int i=0;
	int ch;
	while(((ch=fgetc(fpin))!=EOF)&&(ch!='\n'))
	{
		if(fprintf(fpout,"%d",ch)!=1)
			printf("cannot save\n");
	}
}

void save_fscanf(FILE* fpin,FILE* fpout)
{
	int i;
	for(int count=0;count<116;count++)
	{
		fscanf(fpin,"%d",&i);
		fprintf(fpout,"%d",i);
	}
}

void save_fread(FILE* fpin,FILE* fpout)
{
	int i;
	for(int count=0;count<16;count++)
	{
		fread(&i,sizeof(int),1,fpin);
		fprintf(fpout,"%d ",i);
	}
}

int main()
{
	FILE* fpin;
	FILE* fpout;
	if((fpin=fopen("rectangle.dat","rb"))==NULL)
	{
		printf("cannot open files!\n");
		exit(0);
	}
	if((fpout=fopen("rectangle.txt","w"))==NULL)
	{
		printf("cannot open files!\n");
		exit(0);
	}
	//save_getc(fpin,fpout);
	//save_fscanf(fpin,fpout);
	save_fread(fpin,fpout);
}
