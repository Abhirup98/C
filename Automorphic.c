#include<stdio.h>
int nod(int n)
{
	int s=0;
	while(n!=0)
	{
		n/=10;
		s+=1;
	}
	return s;
}

int main()
{
	int n,s,sqr,res,x=1;
	scanf("%d",&n);
	s=nod(n);
	sqr=n*n;
	while(s!=0)
	{
		x*=10;
		s--;
	}
	res=sqr%x;
	if(res==n)
		printf("Automorphic");
	else
		printf("Not automorphic");
}

