#include<stdio.h>
#define max 30

int arr[max],size;

void insert()
{
	int i;
	printf("Enter the elements of the array: ");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
}

int arr_max()
{
	int m=arr[0],i;
	for(i=1;i<size;i++)
		if(arr[i]>m)
			m=arr[i];
	return m;
}

int cod(int n)
{
	int c=0;
	while(n!=0)
	{
		c++;
		n/=10;
	}
	return c;
}

void sort()
{
	int i,j,k,l;
	int m=arr_max(),d,c,rem;
	int bucket_count[10],bucket[10][10];
	c=cod(m);
	d=1;
	for(i=0;i<c;i++)
	{
		for(j=0;j<10;j++)
			bucket_count[j]=0;
		for(j=0;j<size;j++)
		{
			rem=(arr[j]/d)%10;
			bucket[rem][bucket_count[rem]]=arr[j];
			bucket_count[rem]+=1;
		}
		j=0;
		for(k=0;k<10;k++)
		{
			for(l=0;l<bucket_count[k];l++)
			{
				arr[j]=bucket[k][l];
				j++;
			}
		}
		d*=10;
	}
}

disp()
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

main()
{
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	insert();
	printf("Unsorted array: ");
	disp();
	sort();
	printf("\nSorted array: ");
	disp();
}

