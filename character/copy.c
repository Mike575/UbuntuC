#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	FILE* srcFile,*destFile;
	char ch,hexdata;
	int count,line;
	count=0;line=0;
	if(argc==2)
		printf("input %d argc error\n",argc);
	if((srcFile=fopen(argv[1],"r"))==NULL)
		printf("read %s error\n",argv[1]);
	if((destFile=fopen(argv[2],"wb"))==NULL)
		printf("write %s error\n",argv[2]);
	fprintf(destFile,"\n%08x	",line); 
	while((ch=(fgetc(srcFile)))!=EOF)
		{
			++line;
			if(count==33) count=0;
			else ++count;
			if(count==0)
				fprintf(destFile,"\n%08x	",line); 
//			else if(count>0&&count<=8)
//				fprintf(destFile,"%02x	",ch); 
//			else if(count==9)
//				fprintf(destFile,"	"); 
//			else if(count>9&&count<=16)
//				fprintf(destFile,"%02x	",ch); 
//			else if(count==17)
//				fprintf(destFile,"	"); 
//			else if(count>17&&count<=33)
//				fprintf(destFile,"%02x	",ch); 
		}
}
