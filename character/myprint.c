#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

char* itoa(int n,int radix)
{
	int bit;int i=0;
	char* string;
	string=(char*)malloc(sizeof(char)*100);
	char temp;
	while(n)
	{
		bit=n%radix;
		if(bit<=9)
		{
			string[i++]=bit+'0';
		}
		else
		{
			string[i++]=bit-10+'a';
			if(n/radix==0)
			{
				string[i++]='x';
				string[i++]='0';
			}
		}
		n=n/radix;
	}
	int start,end;
	for(start=0,end=i-1;start<end;start++,end--)
	{
		temp=string[start];
		string[start]=string[end];
		string[end]=string[start];
	}
	string[i]='\0';
	return string;

}


void myprintf(const char* format,...)
{
	va_list ap;
	va_start(ap,format);
	char ch;
	int d,b,x,o,c;
	char* s;
	while(*format)
	{
		ch=*format++;
		if(ch!='%') putchar(ch);
		else
		{
			ch=*format++;
			switch(ch)
			{
				case 'd':d=va_arg(ap,int);
						 fputs(itoa(d,10),stdout);
						 break;
				case 'b':b=va_arg(ap,int);
						 fputs(itoa(b,2),stdout);
						 break;
				case 'x':
				case 'X':x=va_arg(ap,int);
						 fputs(itoa(x,16),stdout);
						 break;
				case 'o':
				case 'O':o=va_arg(ap,int);
						 fputs(itoa(o,8),stdout);
						 break;
				case 'c':c=va_arg(ap,int);
						 putchar(c);
						 break;
				case 's':s=va_arg(ap,char*);
						 fputs(s,stdout);
						 break;
			}
		}
	}
}

int main()
{
	char c;
	int d;
	c='a';d=15;
	myprintf("c=%c;d10=%d;d2=%b;d16=%x;d8=%o\n",c,d,d,d,d);
	return 0;
}
