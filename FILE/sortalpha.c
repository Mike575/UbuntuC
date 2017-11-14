#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE* fp;
	char str[3][10],temp[10];
	int i,j,k,n=3;
	printf("Enter strings:\n");
	for(i=0;i<n;i++)
		fgets(str[i],99,stdin);

	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(str[k],str[j])>0) k=j;
		if(k!=i)
		{
			strcpy(temp,str[i]);
			strcpy(str[i],str[k]);
			strcpy(str[k],temp);
		}
    }
	if((fp=fopen("rectangle.txt","w"))==NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	printf("\nThe new sequence:\n");
	for(i=0;i<n;i++)
	{
		fputs(str[i],fp);
		printf("%s",str[i]);
	}
	fclose(fp);
	
	if((fp=fopen("rectangle.txt","r"))==NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	printf("\nread from file:\n");
	i=0;
	while(fgets(str[i],10,fp)!=NULL)
	{
		printf("%s",str[i]);
		i++;
	}
	fclose(fp);
	return 0;
}
