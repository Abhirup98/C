#include<stdio.h>
#include<math.h>
main()
{
	float x[10],X,h,y[10],d[10][10],s,u,p;
	int n,i,j;
	x[0]=0,x[1]=1,x[2]=2,x[3]=3;
	y[0]=1,y[1]=2,y[2]=11,y[3]=34;
	X=2.8,h=x[1]-x[0],n=4;
	for(i=0;i<n;i++)
		d[i][0]=y[i];
	for(j=1;j<=n-1;j++)
	{
   		for(i=n-1;i>=j;i--)
   		d[i][j]=d[i][j-1]-d[i-1][j-1];
  	}
 	u=(X-x[n-1])/h;
 	p=1;
 	s=y[n-1];
 	for(i=1;i<=n-1;i++)
 	{
   		p=p*(u+i-1)/i;
   		s=s+p*d[n-1][i];
  	}
	printf("%f",s);
}

