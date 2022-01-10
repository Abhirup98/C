#include<stdio.h>

int max,min,a[10];

void m_m(int i,int j)
{
	int max1,min1,m;
	if(i==j)
	{
		max=a[i];
		min=a[i];
	}
	else
	{
		m=(i+j)/2;
		m_m(i,m);
		max1=max;
		min1=min;
		m_m(m+1,j);
		if(max1>max)
			max=max1;
		if(min1<min)
			min=min1;
	}
}

int main()
{
	int i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	m_m(0,n-1);
	printf("\nMaximum = %d",max);
	printf("\nMinimum = %d",min);
}

