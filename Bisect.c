#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x-9*x+1)
#define e 0.0001

main()
{
	float x,x0,x1;
	x0=2,x1=3;
	if(f(x0)*f(x1)<0)
	{
		printf("x0\t\tx1\t\tx\n");
		while(fabs(x0-x1)>e)
		{
			printf("%f\t%f\t%f\n",x0,x1,x);
			x=(x0+x1)/2;
			if(f(x)*f(x0)>0)
			 x0=x;
			else
			 x1=x;
		}
		printf("Root = %f",x);
	}
	else
	 printf("Does not Exist");
}

