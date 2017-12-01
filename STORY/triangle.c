#include<stdio.h>
#define N 9

int main()
{
	int a[N][N];
	int i=0,j=0;
	for(i=0;i<N;i++)
		a[i][0]=a[i][i]=1;
	for(i=2;i<N;i++)
		for(j=1;j<i;j++)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
	for(i=0;i<N;i++)
	{
		for(int count=0;count<=(N*(N+1)/4-i);count++)
			printf(" ");
		for(j=0;j<=i;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}

	int m,n;
	m=0,n=0;
	printf("please enter C(m,n)\n");
	scanf("C(%d,%d)",&m,&n);
	while(m>N||n>N)
	{
		printf("m and n must lower than %d\n",N);
	//	putchar(getchar());	
		scanf("C(%d,%d)",&m,&n);
	}
	printf("C(%d,%d)=%d",m,n,a[m][n]);
}
