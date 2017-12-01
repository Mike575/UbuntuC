#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp;
	int value;
	value=EOF;
	fp=fopen("EOF.dat","wb");
	fwrite(&value,sizeof(int),1,fp);
	printf("EOF: %d\n",EOF);
}
