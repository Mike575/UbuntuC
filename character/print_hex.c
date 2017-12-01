#include<stdio.h>
#include<stdlib.h>

void print_hex(FILE* destFile,char hexdata[16],int length)
{
	for(int i=0;i<length;++i)
	{
		if(hexdata[i]>=0&&hexdata[i]!='\n')
			fprintf(destFile,"%c",hexdata[i]);
		else 
			fprintf(destFile,".");
	}

}
int main(int argc,char* argv[])
{
	char hexdata[16],ch;
	int count,line;
	count=0,line=0;
	FILE *srcFile,*destFile;
	destFile=fopen(argv[2],"wb");
	srcFile=fopen(argv[1],"r"); 
	line=ftell(srcFile);
	fprintf(destFile,"\n%08x   ",line);
	while((ch=fgetc(srcFile))!=EOF)
	{	
		hexdata[count++]=ch;
		fprintf(destFile,"%02x ",ch);

		if(count%16==0&&count>0) 
		{	
			count=0;
			print_hex(destFile,hexdata,16);
			line=ftell(srcFile);
			fprintf(destFile,"\n%08x   ",line);
		}
	}
	if(count!=1)
	{
		for(int i=0;i<16-count;++i)
			fprintf(destFile,"   ");
		print_hex(destFile,hexdata,count);	

	}
	fclose(srcFile);
	fclose(destFile);
	return 0;
}
