#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x*x-x-10)
#define df(x) (4*x*x*x-1)

main()
{
	float x0,x,e=0.0001;
	int i,n=10;
	printf("Enter the value of x0: ");
	scanf("%f",&x0);
	for(i=1;i<=n;i++)
	{
		x=x0-f(x0)/df(x0);
		if(fabs(f(x))<e)
		{
			printf("The real root of the equation x^4-x-10 is = %f",x);
			break;
		}
		else
			x0=x;
	}
}

