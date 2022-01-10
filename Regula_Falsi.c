#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x-3*x-5)
main()
{
	float x, x0 = 2, x1 = 3, e;
	int i, n = 10;
	if (f(x0)*f(x1) > 0)
		printf("Does not Exist");
	else
	{
		e = 0.0001;
		for (i = 1;i <= n;i++)
		{
			x = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
			if (fabs(f(x)) < e)
			{
				printf("The root of the equation x^3-3x-5 is %f", x);
				break;
			}
			if (f(x)*f(x0) > 0)
				x0 = x;
			else
				x1 = x;
		}
	}
}

