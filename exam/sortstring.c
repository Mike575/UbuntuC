#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct line
{
	char string[1000];
	int length;
	int hash_value;
}line;

int hash(char* s)
{
	char ch;
	int sum;
	int hash_value;
	while((ch=*(s++))!='\0')
	{
		if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			sum+=ch;
		}
	}
	hash_value=sum%10007;
	return hash_value;
}

int compare(line a,line b)
{
//	if(a.hash_value>b.hash_value) return 1;
//	else if(a.hash_value==b.hash_value)
//	{
		if(a.length>b.length) return 1;
		else if(a.length==b.length)
		{
			if(strcmp(a.string,b.string)>0) return 1;
		}
//	}
	return 0;
}

void quicksort(int position[],line R[],int low,int high)
{
	// aim at sorting position[];
	// i_pos and j_pos control position[];
	// after sort elements at leftside smaller than basic,
	// and elements at rightside bigger than basic;
	int basic_temp; 
	line basic;
	int i_pos=low;
	int j_pos=high;
	int i=position[i_pos],j=position[j_pos];
	if(low<high)
	{
		basic_temp=position[low];//
		basic=R[basic_temp];
		while(i_pos!=j_pos)
		{
			
			while(i_pos<j_pos&&(compare(basic,R[j])<0))
			{
				j=position[--j_pos];
			}
			if(i_pos<j_pos)
			{
				position[i_pos]=position[j_pos];
				i=position[++i_pos];
			}
			while(i_pos<j_pos&&(compare(R[i],basic)<0))
			{
				i=position[++i_pos];
			}
			if(i_pos<j_pos)
			{
				position[j_pos]=position[i_pos];
				j=position[--j_pos];
			}
		}
			
		position[i_pos]=basic_temp;
		quicksort(position,R,low,i_pos-1);
		quicksort(position,R,i_pos+1,high);
	}
	
}

int main(int argc,char** argv)
{
	FILE* fpin,*fpout;
	fpin=fopen("data.in","r");
	fpout=fopen("data.out","w");
	int n=8;//(int)(argv[1]-'0');
	line a[n];
	int position[n];
	for(int pos=0;pos<n;pos++)
	{
		position[pos]=pos;
	}
	char ch;int i=0;int j=0;
	while((ch=fgetc(fpin))!=EOF)
	{
		for(j=0;ch!='\n';j++)
		{
			a[i].string[j]=ch;
			ch=fgetc(fpin);
		}
		a[i].string[j]='\0';
		a[i].length=j;//
		a[i].hash_value=hash(a[i].string);
		i=i+1;
	}

	quicksort(position,a,0,n-1);

	for(int i=0;i<n;i++)
	{
		fprintf(fpout,"%s\n",a[position[i]].string);
	}
	fclose(fpin);
	fclose(fpout);
	return 0;

}
