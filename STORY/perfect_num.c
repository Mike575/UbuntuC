#include<stdio.h>
#include<math.h>

int main()
{
	long long int a,i,n,s,M;
	M=0x7fffffffffffffff;
	printf("serach form 0 to %lld\n",M);
	for(a=2;a<=M;a++)
	{
		n=0;
		s=a;
		for(i=1;i<a;i++)
			if(a%i==0)
			{
				n++;
				s=s-i;
			}
		if(s==0)
		{
			printf("%lld IS A PERFECT_NUM,IT OWNS %lld factors\n",a,n);
		}
	}
	return 0;
}
