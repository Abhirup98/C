#include<stdio.h>
int main()
{
	int n=-99999999,max1=n,max2=n;
	do{
		scanf("%d",&n);
		if(max1<n && n!=-1)
		{
			max2 = max1;
			max1 = n;
		}
	}while(n!=-1);
	printf("%d",max2);
}

