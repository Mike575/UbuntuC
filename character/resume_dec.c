#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	char delete_char[20];
	int count,delta,ch;
	long cur,end;
	count=0;
	FILE *srcFile,*destFile;
	destFile=fopen(argv[2],"w");
	srcFile=fopen(argv[1],"rb"); 
	fscanf(srcFile,"%08x",&delta);
	while(fscanf(srcFile,"%02x",&ch)!=EOF)
	{	
		count++;
		fprintf(destFile,"%c",ch);
		cur=ftell(srcFile);
		fseek(srcFile,0L,SEEK_END);
		end=ftell(srcFile);
		fseek(srcFile,cur,SEEK_SET);

		printf("end of file is %ld\n",end);
		printf("cur of file is %ld\n",cur);
		printf("end-1-(cur+count+3*(16-count)) is %ld\n",end-1-(cur+count+3*(16-count)));
		if((cur+count+3*(16-count))>=end-1) break;
//g		if(ch>=0&&ch<=127)
//g			fprintf(destFile,"%c",ch);
//g		else
//g			fprintf(destFile,"*");
		if(count%16==0&&count>0) 
		{	
			count=0;
			fgets(delete_char,20,srcFile);
			fscanf(srcFile,"%08x",&delta);
		}
	}
	fclose(destFile);
	fclose(srcFile);
	return 0;
}
