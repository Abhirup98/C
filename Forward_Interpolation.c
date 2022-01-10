#include<stdio.h>

main()
{
	float x[4]={1,2,3,4},y[4]={1,2,11,34},d[4][4]={0};
	float X=2.8,u,p=1,s,n=4,h;
	int i,j;
	s=y[0];
	h=x[1]-x[0];
	for(i=0;i<n;i++);
		d[i][0]=y[i];
	for(j=1;j<n;j++)
		for(i=0;i<=n-j;i++)
			d[i][j]=d[i+1][j-1]-d[i][j-1];
	u=(X-x[0])/h;
	for(i=1;i<=n-1;i++)
	{
		p=p*(u-i+1)/i;
		s=s+p*d[0][i];
	}
	printf("Y = %f\n",s);
	for(i=0;i<4;i++)
	{
		printf(" %.1f",x[i]);
		for(j=0;j<n-i;j++)
			printf(" %.1f",d[i][j]);
		printf("\n");
	}
}

